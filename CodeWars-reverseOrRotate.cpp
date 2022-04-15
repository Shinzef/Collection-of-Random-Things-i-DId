#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

std::string revRot(const std::string string, unsigned int sz)
{
	if ( sz <= 0 || string.empty() )
	{
		return "";
	}
	std::stringstream ss;

	for ( unsigned int i = 0 ; i < string.size() ; i += sz )
	{
		if ( i + sz > string.size() )
		{
			break;
		}
		std::string sub = string.substr(i, sz);
		int sum = 0;

		for ( auto a : sub )
		{
			int n = a - '0';
			sum += pow(n, 3);
		}
		if ( sum % 2 == 0 )
		{
			std::reverse(sub.begin(), sub.end());
			ss << sub;
		}
		else
		{
			ss << sub.substr(1) + sub[0];
		}
	}
	return ss.str();
}
