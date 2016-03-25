//Oniel Toledo   Assignment 10   CS202
//This header file contains class definition and class member definitions
//for the statisticsPkg object. Since all the functions will be templates
//there will be no implementation file, rather, all functions will be 
//defined bellow the class declaration.
//The class is capable of performing various statistical calcuations such
//finding smallest and largest values, finding median, average, standard
//deviation, coVariance, linear correlation, and pearson's coefficeincy
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>//used for rand() function
#include <limits>//used for numeric_limits function
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~Class definition~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//class header for the statisticsPkg class object
template <class myType>
class statisticsPkg{
 public:
  //constructors and destructor
  //sets length to 0 and mySet pointer to NULL
  statisticsPkg();
  //via deep copy, the contents of the input array will be stored
  //into the current class object's index with a size specified by int
  statisticsPkg(int, myType[]);
  //destructor - calls upon free memory
  ~statisticsPkg();
  //class functions
  //returns index contents of passed object
  myType getDatum(int) const;
  //sets a value into a specific index
  void setDatum(int, myType);
  //reads a size for the array by the user, has a try-catch error checking
  int readCount();
  //creates new random set
  void generateNewSet(int);
  //outputs set 3 per line
  void printSet() const;
  //returns smallest value
  myType minimum() const;
  //return largest value
  myType maximum() const;
  //returns median value
  myType median() const;
  //returns the sum of the array
  myType sum() const;
  //returns the mean of the array
  myType average() const;
  myType standardDeviation() const;
  //sorts the array from smallest to largest
  void shellSort();
  //calculates teh variance fo the passed object and the current class object
  myType coVariance(const statisticsPkg&) const;
  //calcuates based on the current class object and the passed object
  myType pearsonsCoefficient(const statisticsPkg&) const;
  //calcuates the linear correlation coefficient of the current class and 
  //the a passed object
  myType linearCorrelationCoefficient(const statisticsPkg&) const;
  //constants
  static const int CNT_MIN=5;//minimum array size
  static const int CNT_MAX=9999;//maximum array size
  static const int RND_LIMIT=999;//limit to random number generation

private:
  void freeMemory();//deletes the array called by the generateNewSet and destructor
  int setLength;
  myType *mySet;//pointer
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Since all of statisticsPkg's functions will be tempates all functions
//will be included in the header file, meaning there is no need for a
//seperate implementation file

//~~~~Class definitions~~~~
//constructor with no parameters, sets setLength variable to 0, and mySet array pointer to NULL
template <class myType>
statisticsPkg<myType>::statisticsPkg(){
  setLength =0;
  mySet=NULL;
}

//copy constructor, the passed 'size' variable represents the size of object, the 'passedObject'
//myType parameter is an input object if valid and if 'size' is within 5-9999 the constructor
//will create an array from the pointer mySet and deep-copy the contents of the passed object
//to the current class object array  
template <class myType>
statisticsPkg<myType>::statisticsPkg(int size, myType pObj[]){
  if(pObj==NULL){//if passed object is null, dsply error, set setLength to 0, and mySet=NULL
    cout << "Error (constructor), invalid input array." << endl;
    setLength=0;
    mySet=NULL;
  }
  else
    if(pObj!=NULL){//if passed object is ok
      if(size>9999 || size<5){//if passed length is invalid, error msg, setLength=0, and mySet=NULL
	cout << "Error (constructor), invalid set length." << endl;
	setLength=0;
	mySet=NULL;
      }
      else
	if(size>=5 && size<=9999){
	  //at this point passedArray and size are both valid, now dynamically create new array and 
	  //copy contents of passedArray into the object array mySet
	  setLength=size;//setLength assigned to the value of the passed parameter
	  //create an array for the mySet pointer of size setLength
	  mySet = new myType[setLength]; 
	  for(int i=0;i<setLength;i++)
	    mySet[i] = pObj[i];
	  
	}
    }
}

//destructor-explicity deallocates the out of scope objects via the freeMemory function
template <class myType>
statisticsPkg<myType>::~statisticsPkg(){
  statisticsPkg<myType>::freeMemory();
}

//the freeMemory function deletes any created array from the pointer mySet
template<class myType>
void statisticsPkg<myType>::freeMemory(){
  if(mySet!=NULL){
    //for(int i=setLength-1; i>=0;i--)
    //delete mySet[i]; //delete each array index of mySet
    delete []mySet; //delete the array created by mySet
    mySet=NULL;
  }
}

//shellSort algorithm function
//follows the algorithm to sort the array from smallest to largest
template <class myType>
void statisticsPkg<myType>::shellSort(){
  int h=1, j=0;
  myType tmp;
  while((h*3+1) < setLength){
    h = 3*h+1;
  }
  while(h>0){
    for(int i=h-1; i < setLength;i++){
      tmp = mySet[i];
      for(j=i; (j>=h)&&(mySet[j-h]>tmp); j -=h)
	mySet[j] = mySet[j-h];
      mySet[j] = tmp;
    }
    h = h/3;
  }
}

//return the item in location 'i' of 'passedArray'
template <class myType>
myType statisticsPkg<myType>::getDatum(int i) const{
  if(i>=setLength || i<0){//if passed index is out of range error message
    cout << "Error (getDatum), index out of range." << endl;
    return 0;
  }
  else //if valid return the myType item located in mySet[i]
    if(i>=0 && i<setLength){
      return (mySet[i]);
    }
}

//copies the contents of the index i of the 'passedObj' array to 
//the array index at i for the current class object
template <class myType>
void statisticsPkg<myType>::setDatum(int i, myType pObj){
  if(i<0 ||i>=setLength)//if i is out of range of the current object
    cout << "Error (setDatum), index out of range." << endl;//error
  else
    if(i>=0 && i<setLength){
      mySet[i] = pObj;
    }//set the index i in the current object to that of the i in passedObj
}

template <class myType>
void statisticsPkg<myType>::generateNewSet(int length){
  if(length<CNT_MIN || length>CNT_MAX)//error checking for length
    cout << "Error (generate), invalid set length." << endl;
  else//good length passed, new set will be created
    if(length>=CNT_MIN && length<=CNT_MAX){
      //if a set already exists call on freeMemory() to delete it,
      //if set is NULL freeMemory will do nothing.
      statisticsPkg::freeMemory();
      setLength = length;//'length' is valid assign 'setLength' to it
      //mySet array has been deleted, now created a new array
      mySet = new myType[length];//create  new array of size 'length' & data type myType
	//now set random values to the new set
      for(int i=0; i<setLength; i++)
	mySet[i] = static_cast<myType>(rand()%RND_LIMIT);  
    }
}

//function to determine and return the largest value in the array
template <class myType>
myType statisticsPkg<myType>::maximum() const{
  //create a temp and set its value to the value of the current object's index 0
  myType tmp = getDatum(0); 
  for(int i=1; i<setLength; i++){
    if(getDatum(i)>tmp)//if the next block is bigger than tmp
      tmp = getDatum(i);//set tmp to that value
  }
  return tmp;//return the largest value in the object array
}

//function to determine and return the smallest value in the array,
//operates exactly like the maximum() function above apart for the '>' to '<' change
template <class myType>
myType statisticsPkg<myType>::minimum() const{
  //create a tmp object that will store the smallest value
  myType tmp = statisticsPkg<myType>::getDatum(0);
  for(int i=1; i<setLength;i++){
    if(statisticsPkg<myType>::getDatum(i)<tmp)
      tmp = getDatum(i);
  }
  return tmp;
}

//assuming that the array has been sorted calculate the median
template <class myType>
myType statisticsPkg<myType>::median() const{
  //variables
  int tmpEvenOdd;
  myType tmpAverage = 0;

  //finds the median depenant on an even or odd sized array
  if(setLength%2==1){//if odd
    tmpEvenOdd = setLength/2;//divide by two
    return mySet[tmpEvenOdd];//return that calculation
  }
  else
    if(setLength%2==0){//even, need to find average of two
      for(int i=0;i<setLength;i++)
	tmpAverage += mySet[i]; 
      return (tmpAverage/setLength);
    }
}

//function for finding the sum of the array
template <class myType>
myType statisticsPkg<myType>::sum() const{
  myType tmpSum=0;//will store the sum 
  for(int i=0;i<setLength;i++)
    tmpSum += mySet[i];//add up all values
  return tmpSum;//return total
}

//function for finding the average
template<class myType>
myType statisticsPkg<myType>::average() const{
  myType tmpAverage=0;
  for(int i=0; i<setLength;i++)
    tmpAverage += mySet[i];
  tmpAverage /= setLength;
  return tmpAverage;
}


//function to read a count from a user, because of the possiblity
//of incorrect data from the user, the function uses 'try/catch' 
//exception handling functionality
template <class myType>
int statisticsPkg<myType>::readCount(){
  string errMsg = "Error, count out of range";
  bool done = false;
  int num, errCnt=0;
  do{//run at least one time
    try{//try block for exception handling
      cout << "Enter Count (5-9999): ";
      cin >> num;//input from user
      cout << endl;
      //verify if incorrect data has been inputted
      if(!cin)//if no input is entered 
	throw errMsg;//throw errMsg string to catch
      else
	if(num<CNT_MIN || num>CNT_MAX){//if num is numeric but outside of range
	  cout << "Error (read), count Value " << num << " not between 5 and 9999." << endl;
	  errCnt++;//error has occured add by 1
	}
	else{//for all other possibilities
	  done = true;//set done to true	     
	     }
    }//end of try
    catch(string errMsg){
      cout << errMsg << endl;
      errCnt++;//error has occured add by 1
      cin.clear();//clease fault bit 
      cin.ignore(numeric_limits<myType>::max(),'\n');
    }//end of catch  statment
    
    if(errCnt==4){//if the user has entered error 4 times
      cout << "Sorry, too many errors." << endl;//error msg
      num=0;
      done=true;//exit and return 0
    }
  }while(!done);   
    return num;
}
 
//function to calculate standard deviation 
template <class myType>
myType statisticsPkg<myType>::standardDeviation() const{
  myType stdDev, tmp=0;
  //will first calculate the numerator-stored as 'tmp'
  for(int i=0; i<setLength;i++)
    tmp += pow((mySet[i]-average()),2);
  stdDev = sqrt(tmp/setLength);
  return stdDev;//retrun calculated stdDev
}

//function fo calculationg coVariance
template <class myType>
myType statisticsPkg<myType>::coVariance(const statisticsPkg& passedObj) const{
  if(setLength==passedObj.setLength){
    myType coVar, tmp=0;
    for(int i=0;i<setLength;i++)//calcuate numerator
      tmp += (mySet[i]-average())*(passedObj.getDatum(i)-passedObj.average());
    coVar = tmp/(setLength-1);
    return coVar; //return calcuation
  }
  //if the current class object and the passed object are not the same length
  //set error message and do not calcuate variance
  else
    if(setLength!=passedObj.setLength){
      cout << "Error (coVariance), invalid data set sizes." << endl;
      return 0;
    }
}


//function to calcuate the pearson coefficient
template <class myType>
myType statisticsPkg<myType>::pearsonsCoefficient(const statisticsPkg& pObj) const{
  //error check for the possibility of invalid data set lengths...
  if(setLength==pObj.setLength){//if data sets are equivalent
    myType numerator=0, denominator, pCoef;
    for(int x=0;x<setLength;x++)
      numerator += (mySet[x]-average())*(pObj.mySet[x]-pObj.average());
    denominator = (setLength-1)*standardDeviation()*pObj.standardDeviation();
    pCoef = numerator/denominator;
    return pCoef;
  }
  else
    if(setLength!=pObj.setLength){
      cout << "Error (pearsonsCoefficient), invalid data set sizes." << endl;
      return 0;
    }
}

//function to calculate linear correlation
template <class myType>
myType statisticsPkg<myType>::linearCorrelationCoefficient(const statisticsPkg& pObj) const{
  if(setLength==pObj.setLength){
    myType coVar;//will store the coVariance between two objects
    myType stdDevCurrent = standardDeviation();//store the stdDeviation for current class
    myType stdDevpObj = pObj.standardDeviation();//for passed object
    coVar = coVariance(pObj);//use the coVariance function to find the variance between sets
    return (coVar/(stdDevCurrent*stdDevpObj));//return calcuation
  }
  else
    if(setLength!=pObj.setLength){//error msg, data sets not equivalent
      cout << "Error (linearCorrelationCoefficient), invalid data set sizes." << endl;
      return 0;
    }
}

//function to print out data sets 3 items per line
template <class myType>
void statisticsPkg<myType>::printSet() const{
  for(int i=0; i<setLength;i++){
    if(i%3==0 || i%3==1)//if i is not in the last column
      cout << " Set[" << i << "] = " << right << setw(8) << showpoint << mySet[i] << setw(4) << " ";
      else
	if(i%3==2)
	  cout << " Set[" << i << "] = " <<right << setw(8) << showpoint << mySet[i] << endl;
  }
  if(setLength%3!=0)//if there is no modulus remainer, add line feed
    cout << endl;
}
