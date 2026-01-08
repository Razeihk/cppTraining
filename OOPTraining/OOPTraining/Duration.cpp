#include "Duration.h"


using namespace std;

Duration::Duration(int hours, int minutes, int seconds)
	:m_hours(hours + (minutes / 60)), m_minutes((minutes % 60) + (seconds / 60)), m_seconds(seconds % 60)
{

}

bool Duration::isEqual(Duration const& b) const
{
	return (m_hours == b.m_hours && m_minutes == b.m_minutes && m_seconds == b.m_seconds);
}

bool Duration::isSmallerThan(Duration const& b) const
{
	if (m_hours < b.m_hours)
	{
		return true;
	}
	else if (m_hours == b.m_hours && m_minutes < b.m_minutes)
	{
		return true;
	}
	else if(m_hours == b.m_hours && m_minutes == b.m_minutes && m_seconds < b.m_seconds)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Duration::isGreaterThan(Duration const& b) const
{
	if (m_hours > b.m_hours)
	{
		return true;
	}
	else if (m_hours == b.m_hours && m_minutes > b.m_minutes)
	{
		return true;
	}
	else if (m_hours == b.m_hours && m_minutes == b.m_minutes && m_seconds > b.m_seconds)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//int Duration::getHours() const
//{
//	return m_hours;
//}
//
//int Duration::getMinutes() const
//{
//	return m_minutes;
//}
//
//int Duration::getSeconds() const
//{
//	return m_seconds;
//}

void Duration::displayTime() const
{
	cout << "Duration is " << m_hours << " hours, " << m_minutes << " minutes and " << m_seconds << " seconds" << endl;
}

void Duration::display(ostream &stream) const
{
	stream << m_hours << "h" << m_minutes << "m" << m_seconds << "s";
}

int Duration::asSeconds() const
{
	return (m_hours * 3600) + (m_minutes * 60) + m_seconds;
}


// GETTERS

int Duration::getSeconds() const
{
	return m_seconds;
}

int Duration::getMinutes() const
{
	return m_minutes;
}

int Duration::getHours() const
{
	return m_hours;
}



// OPERATORS

bool Duration::operator==(Duration const& b)
{
	return isEqual(b);
}

bool operator!=(Duration const& a, Duration const& b)
{
	return !a.isEqual(b);
}

bool operator<(Duration const& a, Duration const& b)
{
	return a.isSmallerThan(b);
}

bool operator>(Duration const& a, Duration const& b)
{
	return a.isGreaterThan(b);
}

bool operator<=(Duration const& a, Duration const& b)
{
	return !a.isGreaterThan(b);
}

bool operator>=(Duration const& a, Duration const& b)
{
	return !a.isSmallerThan(b);
}

void Duration::operator+=(Duration const& a)
{
	m_seconds += a.m_seconds; // Adds the seconds together
	m_minutes += m_seconds / 60; // Adds to the minutes the number of times the seconds are over 60
	m_seconds %= 60; // Sets the remaining seconds

	m_minutes += a.m_minutes;
	m_hours += m_minutes / 60;
	m_minutes %= 60;

	m_hours += a.m_hours;
}

void Duration::operator+=(int const seconds)
{
	m_seconds += seconds; // Adds the seconds together
	m_minutes += m_seconds / 60; // Adds to the minutes the number of times the seconds are over 60
	m_seconds %= 60; // Sets the remaining seconds

	m_hours += m_minutes / 60;
	m_minutes %= 60;
}

Duration operator+(Duration const& a, Duration const& b)
{
	Duration returnedValue(a); // Creates a copy of a
	returnedValue += b; // Adds b to a
	return returnedValue; // Returns the result of the addition
}

void Duration::operator-=(Duration const& a)
{
	int resultSeconds = asSeconds() - a.asSeconds();

	m_hours = resultSeconds / 3600;
	int remainingSeconds = resultSeconds % 3600;
	m_minutes = remainingSeconds / 60;
	m_seconds = remainingSeconds % 60;
}

Duration operator-(Duration const& a, Duration const& b)
{
	Duration temp = a;
	temp -= b;
	return temp;
}

ostream& operator<<(ostream& stream, Duration const& duration)	// ostream& is because it returns the variable stream, which is a reference
{
	duration.display(stream);
	return stream;
}