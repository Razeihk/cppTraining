#pragma once
class Duration
{
public:
	Duration() {}; // Declares the default constructor 
	Duration(int hours, int minutes, int seconds); // This defines by default the duration to 0 hour, 0 minute, 0 second
	
	// OPERATORS METHODS

	bool isEqual(Duration const& b) const;
	bool isSmallerThan(Duration const& b) const;
	bool isGreaterThan(Duration const& b) const;
	void displayTime() const;
	int asSeconds() const; // returns the total number of seconds in a duration


	// GETTERS
	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;


	// OPERATORS
	void operator+=(Duration const& a);
	void operator+=(int const seconds); // Allows to add only seconds
	void operator-=(Duration const& a);
	

	//int getHours() const;
	//int getMinutes() const;
	//int getSeconds() const;

private:
	int m_hours = 0; // Can initialise the members directly here
	int m_minutes = 0;
	int m_seconds = 0;
};


// OPERATORS

bool operator==(Duration const& a, Duration const& b);
bool operator!=(Duration const& a, Duration const& b);
bool operator<(Duration const& a, Duration const& b);
bool operator>(Duration const& a, Duration const& b);
bool operator<=(Duration const& a, Duration const& b);
bool operator>=(Duration const& a, Duration const& b);
Duration operator+(Duration const& a, Duration const& b);
Duration operator-(Duration const& a, Duration const& b);