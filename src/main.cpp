//******************************************************************************
// File name:   main.cpp
// Author:      
// Date:        
// Class:       
// Assignment:  
// Purpose:     We want to track weather conditions for the month of December.
//              Each day we will record the high temperature (double), low
//              temperature (double), inches of rainfall (double), and snow
//              fall (double). The data file weather.txt contains the data for
//              the month with a sentinel value of -999.0 for the high
//              temperature.
//
//              You are to write TODOs in order below.
//
//              NOTE: Never read the sentinel value into the array of data

/*
    1. Write a function that outputs the weather information for a single day 
       of weather to a file. The format is to be:

       High: xx.xx  Low: xx.xx  Rain: xx.xx  Snow: xx.xx

    2. Write a function that outputs the weather information for a month of 
       weather to a file. The format is to be:

       Day: 1  High: xx.xx  Low: xx.xx  Rain: xx.xx  Snow: xx.xx
       Day: 2  …

    3. Write a function that computes the biggestChange, which will find the 
       day with the biggest difference between the high and low temperature 
       and return the index of that day in the array.

    4. Write a function that outputs the summary statistics for a given 
       month of data to a file. The format is to be:

       Monthly High: xx.xx
       Monthly Low: xx.xx
       Largest Daily Variance For The Month: xx.xx
*/

// Hours:       
//******************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_DAYS = 31;
const double SENTINEL = -999.0;
const int NO_WEATHER_DATA_INDEX = -1;

// TODO #1: Create a struct capable of storing information for a single day's
//          worth of data. Name the members according to our coding standards.

struct Weather {
  double mHighTemp;
  double mLowTemp;
  double mRainfall;
  double mSnowFall;
};

// TODO #3: Write the function prototype to read in a single day's worth of
//          weather.

void getWeatherDay (ifstream& inFile, Weather& sWeatherDay);

// TODO #5: Write the function prototype to read in the weather data for the
//          month.

void getWeatherMonth (Weather sWeatherData[], int& size, 
                      const string& fileName);

// TODO #8: Write the function prototype to find the hottest day. Return the
//          index value in the array of the day with the hottest day.
//          If there are no values in the array, return -1.

int getHottestDay (const Weather sWeatherData[], int size);

int main () {
  const string FILE_NAME = "data/weather.txt";
  int size = 0;
  int indexOfHighestTemp;
  // TODO #2: Create an array capable of holding a month's worth of information
  Weather sWeatherData[MAX_DAYS];

  // TODO #7: Call the function from TODO #5 to read all weather data from
  //          the file data/weather.txt. Check that you've read in the 
  //          information correctly using the debugger.
  //
  //          NOTE: Show me your loaded up array of structs with the data
  //                from the data file
  getWeatherMonth (sWeatherData, size, FILE_NAME);

  // TODO #10:  Output the highest temperature for the month
  indexOfHighestTemp = getHottestDay (sWeatherData, size);
  if (NO_WEATHER_DATA_INDEX == indexOfHighestTemp) {
    cout << "There is no data" << endl;
  }
  else {
    cout << "Highest Temperature Is: " 
    << sWeatherData[indexOfHighestTemp].mHighTemp << endl;
  }

  return EXIT_SUCCESS;
}

// TODO #4: Write the function definition for TODO #3

void getWeatherDay (ifstream& inFile, Weather& sWeatherDay) {
  inFile >> sWeatherDay.mHighTemp >> sWeatherDay.mLowTemp
    >> sWeatherDay.mRainfall >> sWeatherDay.mSnowFall;
}

// TODO #6: Write the function definition for TODO #5. This function is to 
//          use the function from TODO #3.
void getWeatherMonth (Weather sWeatherData[], int& size, 
                      const string& fileName) {
  ifstream inFile;
  Weather sWeather;

  inFile.open (fileName);
  if (inFile.fail ()) {
    cout << "Error Opening: " << fileName << endl;
    exit (EXIT_FAILURE);
  }

  size = 0;
  getWeatherDay (inFile, sWeather);
  while (sWeather.mHighTemp != SENTINEL) {
    sWeatherData[size] = sWeather;
    size++;
    getWeatherDay (inFile, sWeather);
  }

  inFile.close ();
}

// TODO #9: Write the function definition for TODO #8. 

int getHottestDay (const Weather sWeatherData[], int size) {
  double hottestTemp = sWeatherData[0].mHighTemp;
  int indexOfHottest = NO_WEATHER_DATA_INDEX;

  for (int day = 0; day < size; day++) {
    if (sWeatherData[day].mHighTemp > hottestTemp) {
      hottestTemp = sWeatherData[day].mHighTemp;
      indexOfHottest = day;
    }
  }
  return indexOfHottest;
}