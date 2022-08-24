

/* 

    Solution by Rahul Surana

    ***********************************************************



There is a large manufacturer of vaccine which produces M types of vaccines (whose formulas are derived from different pharma brands). 
The manufacturer needs to divide all the vaccines between N dealers. It is acceptable if some dealers do not get any vaccine. 
However, no dealer wants vaccines of different kinds which means that all vaccines that a dealer gets need to be of the same type.

The manufacturer also knows that dealers will be jealous if a dealer gets too many vaccines.
 As an approximation, the jealousy level among the dealers is defined as the largest number of vaccines given to any dealer.

Task

Help the manufacturer to divide all the vaccines among the dealers such that the jealousy level is minimized.

Example

Assumptions

	N = 5
	M = 2
	arr= [7,4]


Approach


	There are 7x vaccines of  1<sup>st</sup>  type and 4 vaccines of  2<sup>nd</sup>  type. Let the two types be defined by  P  and  Q.   
	 So if the manufacturer divides the vaccines as  PP, PP, PPP, QQ, QQ.  This will be optimal distribution. 
	 Thus, the answer is  3 . 
 

  Function description  

 Complete the function  solve  provided in the editor. This function takes the following  3  parameters and returns the minimum possible jealousy level: 

 
	  N:  Represents the number of dealers 
	  M : Represents the number of types of vaccines 
	  arr:  Represents the array of  M  integers where  arr<sub>i</sub>  represents the number of vaccines of type  i  
 

  Input format  

  Note : This is the input format that you must use to provide custom input (available above the  Compile and Test  button). 

 
	 The first line contains  T  denoting   the number   of test cases.  T  also specifies the number of times you have to run the  solve  function on a different set of inputs. 
	 For each test case:
	 
		 The first line of input contains two positive integers  N  and  M . 
		 The next line contains  M  space-separated positive integers, with the K<sup>th</sup>   integer denoting the number of vaccines of type  K . 
	 
	 
 

  Output format  

 For each test case, print the minimum possible jealousy level in a new line. 



      ***********************************************************
*/

