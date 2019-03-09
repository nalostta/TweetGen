/*-----------------------------------------------------------------------------------------------------
Project	: Introduction to Programming and Computer Systems using C
PHI-Education 
October 5,2018
submitted by : manthan shah
-------------------------------------------------------------------------------------------------------
The submission consists of programs in the bin folder,relevant static and dynamic libraries and 
object files in their respective folders.The source folder contains all the source programs.To 
make all the files, execute command "make all".The command "make clean" removes everything made
,effectively emptying the folders bin,objects and libraries.while testing programs,all the ones that require saving or loading from an external text file need to executed/run from the base folder itself
as the required textfiles exist in this directory.Thus, to run the final tweet generator application,
following command should be executed ".\bin\FinalProject.exe abbrevs.txt"  where abbrevs is the supporting text file containing all the abbreviations and definitions.

UPDATE 1: added batch scripts to automatically start all the necessary programs.The list of executable programs are as follows:
	TweetGen.bat			: 	launches FinalProject.exe which is a tweet generator program.
									NOTE:the program requires relevant txt file containing the abbreviations, the script takes care of this.In case of custom loading abbreviations,the program can be executed from the cmd line or in program.
	DictionaryProgram.bat	:	launches a Simple dictionary program allowing to store,load,search and print out words and their definitions.
									NOTE : This program does not require a txt file as an argument, however it does use one (SavedDictionary.txt).
	GensortTest.bat			:	launches a program to test the genSort function.
	
	RecRevTest.bat			:	launches a program to test a function that recursively reverses a linked list.
	
	ArrayProgram.bat		:	launches an array program which allows you to add,remove,search index,display and sort a set of integers and also to save or load the set into a txt file.
									NOTE	:	This program does not require a txt file as an argument, however it does use one (SavedArray.txt).
	
	StringProgram.bat		:	launches a StringProgram.exe which provides almost the same functionality as that of the ArrayProgram, but in strings.
	
	TokenizeTest.bat		:	launches a program to test the Tokenize function. Tokenize splits a given string into a set of short strings based on an input token. (example : "hello; world!; this is manthan!" is split into 3 strings "","world" and "this is manthan!")
	
	
	
					
	
*/
