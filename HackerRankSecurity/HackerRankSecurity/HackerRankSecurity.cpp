// HackerRankSecurity.cpp : Defines the entry point for the console application.
// Testing class for HackerRank Challenges

#include "stdafx.h"
#include "HackerRankSecurity.h"

int main()
{
	int n;
	const char SPACE = ' ';
	std::string values,tmp;
	std::vector<std::string> splitValues;
	std::vector<int> availableValues;

	//Get the number of iterations
	std::getline( std::cin, tmp );
	n = std::stoi( tmp );

	// Create available values vector
	for( int i = 0; i < n; i++ ) {
		availableValues.push_back( i + 1 );
	}


	std::getline(std::cin, values);

	split( values, splitValues, SPACE );

	for( int i = 0; i < n; i++ )
	{
		// See if the inputted value is a member of the available values
		if( std::find(availableValues.begin(), availableValues.end(), std::stoi( splitValues.at( i ) ) ) == availableValues.end() ) {
			std::cout << "NO" << std::endl;
			return 0;
		}

		// Remove the used value
		std::remove( availableValues.begin(), availableValues.end(), std::stoi( splitValues.at( i ) ) );

	}

	std::cout << "YES" << std::endl;

	return 0;

}

void split( const std::string &string, std::vector<std::string> &outStrings, const char delimiter ) {
	std::string tmp,operatingString;

	operatingString = string;

	// Iterate through the string and split on delimiter
	for( std::string::iterator currentChar = operatingString.begin(); currentChar != operatingString.end(); ++currentChar )
	{
		// If we reach the delimiter, add the string to the list and clear the tmp string
		if( *currentChar == delimiter ) {
			outStrings.push_back( tmp );
			tmp.clear();
		}

		// If we haven't gotten to the delimiter yet, continue to build the string
		else {
			tmp.push_back( *currentChar );
		}
	}

	// If we hit the end, see if there is anything left in the tmp string
	if( tmp.length() ) {
		outStrings.push_back( tmp );
	}
}

