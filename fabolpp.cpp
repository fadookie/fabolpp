/*A 12-bit integer simulator by Eliot Lash
 */
/*This file is part of FABOL++.
 *
 *FABOL++ is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *FABOL++ is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with FABOL++.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

using namespace std;
typedef unsigned short UINT12;

int main()
{
	UINT12 myUInt12 = 4094; //very high 12-bit number
	const UINT12 UInt12_max = 4096; //The cap for a 12-bit number from 0-4095
	cout << "myUInt12 is " << myUInt12 << ".\nIncrement by what value? ";
	UINT12 incrementor;
	cin >> incrementor;
	cout << "(UINT12)incrementor == " << (UINT12)incrementor;
	myUInt12 = myUInt12 + (UINT12)incrementor;
	cout << "\nPre-wrap value: " << myUInt12;
	while (myUInt12 >= UInt12_max) //If myUInt12 goes over 4095, wrap value starting at 0
	{
		myUInt12 = myUInt12 - UInt12_max;
	}
	cout << "\nPost-wrap value: " << myUInt12 << endl;
	//cout << "Size: " << sizeof(myUInt12) << " Bytes." << endl;
	return 0;
}
