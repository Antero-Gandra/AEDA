/**
 * Project Untitled
 */


#include "CompanyMS.h"
#include "Time.h"
#include <iostream>

using namespace std;
/**
 * CompanyMS implementation
 */

 int main()
 {
	 Time time1(2016, 2, 28, 0, 0);
	 Time time2(0, 0, 1, 0, 0);
	 time1 = time1 + time2;
	 if (time2 < time1) {
		 cout << time1.getYear() << endl;
		 cout << time1.getMonth() << endl;
		 cout << time1.getDay() << endl;
	 }
	 int a;
	 cin >> a;

 	 return 0;
 }
