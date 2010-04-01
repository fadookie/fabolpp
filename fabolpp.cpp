/*A 12-bit integer simulator by Eliot Lash
 *
 *This file is part of FABOL++.
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

#define UINT12MAX 4096
#include <iostream>
//#include <string>

using namespace std;
typedef unsigned short UINT12;
//const UINT12 UInt12_max = 4096; //The cap for a 12-bit number from 0-4095

class UInt12
{
	UINT12 myUINT12; //Private value
	UINT12 parse (UINT12 incoming); //wraparound check method
	public:
		UInt12();
		UInt12(UINT12 initialValue);
		UINT12 set (UINT12 incoming); //Setter
		UINT12 get () { return myUINT12; }; //getter
};

UInt12::UInt12 ()
{
	myUINT12 = 0;
}

UInt12::UInt12 (UINT12 initialValue)
{
	//InitialValue is a reference, do not modify it!
	myUINT12 = initialValue;
}

UINT12 UInt12::set (UINT12 incoming)
{
	cout << "\nPre-wrap value: " << incoming;
	while (incoming >= UINT12MAX) //If myUInt12 goes over 4095, wrap value starting at 0
	{
		incoming = incoming - UINT12MAX;
	}
	myUINT12 = incoming;
	cout << "\nPost-wrap value: " << myUINT12 << endl;
	//cout << "Size: " << sizeof(myUInt12) << " Bytes." << endl;
}

int main()
{
	UInt12 testUInt12 = 4093; //very high 12-bit number
	//cout << testUInt12.get() << endl;
	//testUInt12 = 4094;
	//cout << testUInt12.get();
	//testUInt12++;
	//cout << testUInt12.get();
	bool execute = true;
	int incrementor;
	//string input;
	
	cout << "FABOL++ Interpreter Pre-app\n type q to quit.\n";

	while (execute)
	{
		cout << "testUInt12 is " << testUInt12.get() << ".\nIncrement by what value? ";
		cin >> incrementor;
		//incrementor = (int)input;
		/*if (incrementor == (int)"q")
		*{
		*	cout << "(int)\"q\" = " << (int)"q";
		*	execute = false;
		}*/
		if (incrementor >= 0)
		{
			cout << "(UINT12)incrementor == " << (UINT12)incrementor;
			testUInt12.set(testUInt12.get() + (UINT12)incrementor);
		}
		else if (incrementor < 0) //if incrementor is negative
		{
			incrementor *= -1; //flip sign
			cout << "(UINT12)decrementor == " << (UINT12)incrementor;
			testUInt12.set(testUInt12.get() - (UINT12)incrementor);//and subtract
		}
		
	}
	return 0;
}
