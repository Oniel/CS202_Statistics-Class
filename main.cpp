//	CS 202 - Provided Main
//		This main uses the statisticsPkg class for
//		various set of different types

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

#include "statisticsPkg.h"

using namespace std;

int main()
{
// **********************************************************
//  Simple header.

	string	bars, stars, line;
	bars.append(70, '-');
	stars.append(70, '*');
	line.append(70, '=');

	cout << line << endl << "Assignment #10 -  Statistics Package -> Testing"
		<< endl << endl;

// **********************************************************
//  Some tests for the statisticsPkg class for double type with 10 values.

	double	min0a, max0a, med0a;
	double	min0b, max0b, med0b;
	double	ave0a, ave0b, sum0a, sum0b;
	double	std0a, std0b;
	double	coVar0, corrCoff0, linCoff0;
	double	list0a[] = {2.5, 4.5, 6.5, 9.5, 10.5, 3.5, 8.5, 5.5, 7.5, 1.5};
	double	list0b[] = {12.5, 18.5, 10.5, 13.5, 19.5, 15.5, 16.5, 17.5, 11.5, 14.5};
	int	list0len = sizeof(list0a)/sizeof(double);

	{
		statisticsPkg<double> set0a(list0len, list0a);
		statisticsPkg<double> set0b(list0len, list0b);
		
		cout << stars << endl;
		cout << "Data set - Doubles" << endl;

		cout << endl << "Data Set A for double type (unsorted):" << endl;
		set0a.printSet();
		cout << endl;

		cout << endl << "Data Set B for double type (unsorted):" << endl;
		set0b.printSet();
	      
		min0a = set0a.minimum();
		max0a = set0a.maximum();
		set0a.shellSort();
		med0a = set0a.median();
		sum0a = set0a.sum();
		ave0a = set0a.average();
		std0a = set0a.standardDeviation();
		min0b = set0b.minimum();
		max0b = set0b.maximum();
		set0b.shellSort();
		med0b = set0b.median();
		sum0b = set0b.sum();
		ave0b = set0b.average();
		std0b = set0b.standardDeviation();

		cout << endl << endl << bars << endl;
		cout << "Data Set A for double type (sorted):" << endl;
		set0a.printSet();
		cout << endl << endl;

		cout << "Statistical Results" << endl;
		cout << "   Data Set A Minimum: " << showpoint << min0a << endl;
		cout << "   Data Set A Maximum: " << showpoint << max0a << endl;
		cout << "   Data Set A Median: " << showpoint << med0a << endl;
		cout << "   Data Set A Sum: " << showpoint << sum0a << endl;
		cout << "   Data Set A Average: " << showpoint << ave0a << endl;
		cout << "   Data Set A Standard Deviation: " << std0a << endl;

		cout << endl << bars << endl;
		cout << "Data Set B for double type (sorted):" << endl;
		set0b.printSet();
		cout << endl << endl;

		cout << "Statistical Results" << endl;
		cout << "   Data Set B Minimum: " << showpoint << min0b << endl;
		cout << "   Data Set B Maximum: " << showpoint << max0b << endl;
		cout << "   Data Set B Median: " << showpoint << med0b << endl;
		cout << "   Data Set B Sum: " << showpoint << sum0b << endl;
		cout << "   Data Set B Average: " << showpoint << ave0b << endl;
		cout << "   Data Set B Standard Deviation: " << std0b << endl;

		cout << endl << bars << endl;
		cout << "Summary Results:" << endl;

		coVar0 = set0a.coVariance(set0b);
		corrCoff0 = set0a.pearsonsCoefficient(set0b);
		linCoff0 = set0a.linearCorrelationCoefficient(set0b);

		cout << "   Covariance: " << coVar0 << endl;
		cout << "   Pearson's Coefficient: " << corrCoff0 << endl;
		cout << "   Linear Correlation Coefficient: " << linCoff0 << endl;
		cout << endl << endl;


	}

//	Note, the enclosure of this section creates an independent block
//	for the purposes of scoping.
//	Thus, the destructor for these objects will be called here!
//	If there is an issue with the descructor, it will show up here
//	(where these objects go out of scope) instead of at the end of the program.

//	This avoids the incorrect thinking that the crashes at the end of the
//	program are somehow OK or not relevant.  :-)


// **********************************************************
//  Some tests for the statisticsPkg class for integer type.

	statisticsPkg <int> set1a;
	statisticsPkg <int> set1b;
	int	min1a, max1a, med1a, sum1a, ave1a, std1a;
	int	min1b, max1b, med1b, sum1b, ave1b, std1b;
	int	coVar1, corrCoff1, linCoff1;

	cout << stars << endl;
	cout << "Data set - Integers" << endl;

	set1a.generateNewSet(11);
	set1a.setDatum(0, 1234);
	set1b.generateNewSet(11);
	set1b.setDatum(0, 4321);

	cout << endl << "Data Set A for integer type (unsorted):" << endl;
	set1a.printSet();

	cout << endl << endl << "Data Set B for integer type (unsorted):" << endl;
	set1b.printSet();

	min1a = set1a.minimum();
	max1a = set1a.maximum();
	set1a.shellSort();
	med1a = set1a.median();
	sum1a = set1a.sum();
	ave1a = set1a.average();
	std1a = set1a.standardDeviation();

	min1b = set1b.minimum();
	max1b = set1b.maximum();
	set1b.shellSort();
	med1b = set1b.median();
	sum1b = set1b.sum();
	ave1b = set1b.average();
	std1b = set1b.standardDeviation();

	cout << endl << endl << bars << endl;
	cout << "Data Set A for integer type (sorted):" << endl;
	set1a.printSet();
	cout << endl << endl;

	cout << "Statistical Results" << endl;
	cout << "   Data Set A Minimum: " << min1a << endl;
	cout << "   Data Set A Maximum: " << max1a << endl;
	cout << "   Data Set A Median:  " << med1a << endl;
	cout << "   Data Set A Sum: " << sum1a << endl;
	cout << "   Data Set A Average: " << ave1a << endl;
	cout << "   Data Set A Standard Deviation: " << std1a << endl;

	cout << endl << bars << endl;
	cout << "Data Set B for integer type (sorted):" << endl;
	set1b.printSet();
	cout << endl << endl;

	cout << "Statistical Results" << endl;
	cout << "   Data Set B Minimum: " << min1b << endl;
	cout << "   Data Set B Maximum: " << max1b << endl;
	cout << "   Data Set B Median:  " << med1b << endl;
	cout << "   Data Set B Sum: " << sum1b << endl;
	cout << "   Data Set B Average: " << ave1b << endl;
	cout << "   Data Set B Standard Deviation: " << std1b << endl;

	cout << endl << bars << endl;
	cout << "Summary Results:" << endl;

	coVar1 = set1a.coVariance(set1b);
	corrCoff1 = set1a.pearsonsCoefficient(set1b);
	linCoff1 = set1a.linearCorrelationCoefficient(set1b);

	cout << "   Covariance: " << coVar1 << endl;
	cout << "   Pearson's Coefficient: " << corrCoff1 << endl;
	cout << "   Linear Correlation Coefficient: " << linCoff1 << endl;
	cout << endl << endl;

	
// **********************************************************
//  Some tests for the statisticsPkg class for double type.

	statisticsPkg <float> set2a, set2b;
	float	min2a, max2a, med2a;
	float	min2b, max2b, med2b;
	float	ave2a, ave2b, sum2a, sum2b;
	float	std2a, std2b;
	float	coVar2, corrCoff2, linCoff2;

	cout << stars << endl;
	cout << "Data set - Floats" << endl;

	set2a.generateNewSet(25);
	set2a.setDatum(0, 3.14);

	set2b.generateNewSet(25);
	set2b.setDatum(0, 6.28);

	cout << endl << "Data Set A for float type (unsorted):" << endl;
	set2a.printSet();
	cout << endl;

	cout << endl << "Data Set B for float type (unsorted):" << endl;
	set2b.printSet();

	min2a = set2a.minimum();
	max2a = set2a.maximum();
	set2a.shellSort();
	med2a = set2a.median();
	sum2a = set2a.sum();
	ave2a = set2a.average();
	std2a = set2a.standardDeviation();

	min2b = set2b.minimum();
	max2b = set2b.maximum();
	set2b.shellSort();
	med2b = set2b.median();
	sum2b = set2b.sum();
	ave2b = set2b.average();
	std2b = set2b.standardDeviation();

	cout << endl << endl << bars << endl;
	cout << "Data Set A for float type (sorted):" << endl;
	set2a.printSet();
	cout << endl << endl;

	cout << "Statistical Results" << endl;
	cout << "   Data Set A Minimum: " << showpoint << min2a << endl;
	cout << "   Data Set A Maximum: " << showpoint << max2a << endl;
	cout << "   Data Set A Median: " << showpoint << med2a << endl;
	cout << "   Data Set A Sum: " << showpoint << sum2a << endl;
	cout << "   Data Set A Average: " << showpoint << ave2a << endl;
	cout << "   Data Set A Standard Deviation: " << std2a << endl;

	cout << endl << bars << endl;
	cout << "Data Set B for float type (sorted):" << endl;
	set2b.printSet();
	cout << endl << endl;

	cout << "Statistical Results" << endl;
	cout << "   Data Set B Minimum: " << showpoint << min2b << endl;
	cout << "   Data Set B Maximum: " << showpoint << max2b << endl;
	cout << "   Data Set B Median: " << showpoint << med2b << endl;
	cout << "   Data Set B Sum: " << showpoint << sum2b << endl;
	cout << "   Data Set B Average: " << showpoint << ave2b << endl;
	cout << "   Data Set B Standard Deviation: " << std2b << endl;

	cout << endl << bars << endl;
	cout << "Summary Results:" << endl;

	coVar2 = set2a.coVariance(set2b);
	corrCoff2 = set2a.pearsonsCoefficient(set2b);
	linCoff2 = set2a.linearCorrelationCoefficient(set2b);

	cout << "   Covariance: " << coVar2 << endl;
	cout << "   Pearson's Coefficient: " << corrCoff2 << endl;
	cout << "   Linear Correlation Coefficient: " << linCoff2 << endl;
	cout << endl << endl;
	
// **********************************************************
//  Some tests for the statisticsPkg class for chars.

	char	ltrs[] = {'y', 'u', 'a', 'e', 'i', 'o'};
	char	min3, max3;
	statisticsPkg <char> set3(sizeof(ltrs), ltrs);

	cout << stars << endl;
	cout << "Data set - chars" << endl;

	cout << endl << "Data for char type (unsorted):" << endl;
	set3.printSet();

	set3.shellSort();
	min3 = set3.minimum();
	max3 = set3.maximum();

	cout << endl << endl << "Data for char type (sorted):" << endl;
	set3.printSet();
	cout << endl << endl;

	
// **********************************************************
//  Some tests for the statisticsPkg class for string type.

	string	colors[] = {"Black", "Brown", "Red", "Orange",
						"Yellow", "Green", "Blue", "Violet",
						"Grey", "White"};
	string	min4, max4;
	statisticsPkg <string> set4((sizeof(colors) / sizeof(colors[0])), colors);

	cout << stars << endl;
	cout << "Data set - chars" << endl;

	cout << endl << "Data for string type (unsorted):" << endl;
	set4.printSet();

	set4.shellSort();
	min4 = set4.minimum();
	max4 = set4.maximum();

	cout << endl << endl << "Data for string type (sorted):" << endl;
	set4.printSet();
	cout << endl << endl;

	
// **********************************************************
//  Some tests for the statisticsPkg class for long type.

	statisticsPkg <long long> set5;
	long long	min5, max5, med5, second5, itm;
	long long	sum5, ave5, std5;
	int		len5 = 7;

	cout << stars << endl;
	cout << "Data set - Long Long" << endl;

	set5.generateNewSet(len5);

	cout << endl << "Data for long long type (unsorted):" << endl;
	set5.printSet();

	for (int i=0; i<len5; i++) {
		itm = set5.getDatum(i) * 2;
		set5.setDatum(i, itm);
	}

	min5 = set5.minimum();
	max5 = set5.maximum();
	set5.shellSort();
	med5 = set5.median();
	sum5 = set5.sum();
	ave5 = set5.average();
	std5 = set5.standardDeviation();

	cout << endl << endl << "Data Set Minimum: " << min5 << endl;
	cout << "Data Set Maximum: " << max5 << endl;
	cout << "Data Set Median: " << med5 << endl;
	cout << "Data Set Sum: " << sum5 << endl;
	cout << "Data Set Average: " << ave5 << endl;
	cout << "Data Set Standard Deviation: " << std5 << endl;

	cout << endl << bars << endl;
	cout << endl << "Data for long long type (sorted):" << endl;
	set5.printSet();
	cout << endl << endl;

// **********************************************************
//  Misc error testing...

	int	lst1[] = {1, 9, 0, 2, 7, 8, 3, 5, 4, 6};
	int	lst2[] = {1, 9, 2, 7, 8, 3, 5, 4, 6};
	int	len;
	int	coVarE, corrCoffE, linCoffE;

	len = sizeof(lst1) / sizeof(int);

	cout << stars << endl;
	cout << "Error Testing - Integer Type" << endl << endl;

	statisticsPkg<int> err1(-3, lst1);		// error
	statisticsPkg<int> err3(1000000, lst1);		// error
	statisticsPkg<int> err4(3, lst1);		// error
	statisticsPkg<int> err2(10, NULL);		// error

	statisticsPkg<int> good1(len, lst1);		// good
	statisticsPkg<int> good2(len-1, lst2);		// good
	statisticsPkg<int> good3;			// good

	good1.setDatum(-3, 15);				// error
	good1.setDatum(30000, 15);			// error
	good1.getDatum(-3);				// error
	good1.getDatum(30000);				// error
	good1.generateNewSet(10001);			// error
	good1.generateNewSet(-5);			// error
	good1.generateNewSet(3);			// error

	good1.generateNewSet(5);			// good

	coVarE = good1.coVariance(good2);			// error
	coVarE = good1.coVariance(good3);			// error
	corrCoffE = good1.pearsonsCoefficient(good2);		// error
	corrCoffE = good1.pearsonsCoefficient(good3);		// error
	linCoffE = good1.linearCorrelationCoefficient(good2);	// error
	linCoffE = good1.linearCorrelationCoefficient(good3);	// error

	cout << endl << bars << endl;
	cout << endl << "Data for int type (sorted):" << endl;
	good1.shellSort();				// good
	good1.printSet();				// good
	cout << endl << endl;

// **********************************************************
//  Some tests for the statisticsPkg class for short type.

	statisticsPkg <short> set6a, set6b;
	short	min6a, max6a, med6a, sum6a, ave6a, std6a;
	short	min6b, max6b, med6b, sum6b, ave6b, std6b;
	short	coVar6, corrCoff6, linCoff6;
	int	len6;

	cout << stars << endl;
	cout << "Data set - Shorts" << endl;
	cout << endl;

	len6 = set6a.readCount();

	if ( len6 > 0 ) {
		set6a.generateNewSet(len6);
		set6b.generateNewSet(len6);

		for (int i=0; i<len6; i++) {
			itm = set6a.getDatum(i) / 10;
			set6a.setDatum(i, itm);
			itm = set6b.getDatum(i) / 10;
			set6b.setDatum(i, itm);
		}

		cout << endl << "Data Set A for short type (unsorted):" << endl;
		set6a.printSet();
		cout << endl;
		cout << endl << "Data Set B for short type (unsorted):" << endl;
		set6b.printSet();

		cout << endl << endl << bars << endl;

		min6a = set6a.minimum();
		max6a = set6a.maximum();
		set6a.shellSort();
		med6a = set6a.median();
		sum6a = set6a.sum();
		ave6a = set6a.average();
		std6a = set6a.standardDeviation();

		cout << "Data Set A for short type (sorted):" << endl;
		set6a.printSet();

		cout << endl << endl;
		cout << "Data Set Minimum: " << min6a << endl;
		cout << "Data Set Maximum: " << max6a << endl;
		cout << "Data Set Median:  " << med6a << endl;
		cout << "Data Set Sum:     " << sum6a << endl;
		cout << "Data Set Average: " << ave6a << endl;
		cout << "Data Set Standard Deviation: " << std6a << endl;

		min6b = set6b.minimum();
		max6b = set6b.maximum();
		set6b.shellSort();
		med6b = set6b.median();
		sum6b = set6b.sum();
		ave6b = set6b.average();
		std6b = set6b.standardDeviation();

		cout << endl << bars << endl;
		cout << "Data Set B for short type (sorted):" << endl;
		set6b.printSet();

		cout << endl << endl;
		cout << "Data Set Minimum: " << min6b << endl;
		cout << "Data Set Maximum: " << max6b << endl;
		cout << "Data Set Median:  " << med6b << endl;
		cout << "Data Set Sum:     " << sum6b << endl;
		cout << "Data Set Average: " << ave6b << endl;
		cout << "Data Set Standard Deviation: " << std6b << endl;

		cout << endl << bars << endl;
		coVar6 = set6a.coVariance(set6b);
		corrCoff6 = set6a.pearsonsCoefficient(set6b);
		linCoff6 = set6a.linearCorrelationCoefficient(set6b);

		cout << "   Covariance: " << coVar6 << endl;
		cout << "   Pearson's Coefficient: " << corrCoff6 << endl;
		cout << "   Linear Correlation Coefficient: " << linCoff6 << endl;

		cout << endl << endl;
	}


// **********************************************************
//  All done, just exit.

	return 0;
}


