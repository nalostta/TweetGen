/*
Final Project
author:-manthan shah

Tweet creator application:
loads a predefined set of short forms from a textfile that user inputs as a command line argument
It will then prompt the user to enter a phrase.
If the application can convert it into a tweet ( string size < 140 characters),
it will do so and print the result,else print error message.

*/
#include<stdio.h>
#include<string.h>
#include <time.h>
#include"dbg.h"
#include"milestone-10.h"
#include"milestone-12.h"
#include"milestone-6.h"

#define ITERATION_LIMITD 9999
#define PHRASEBUFF 500
#define SHORTBUFF 15
#define LONGBUFF 40
#define tweetgen_menu()	printf("MENU:\n1.Convert a string to tweet\n2.Add new word to dictionary\n3.Save the current dictionary to a file\n4.Batch load new dictionary items from a file\n5.Set logger settings\n6.Exit\n\ncommand:")
#define logger_menu() printf("\nlogger settings:\n1.log successful conversions\n2.log failed conversions\n3.log both\n\nset :")

int tweetgen(char* phrase,int phraseLength,struct entry* trav);

int main(int argc,char* argv[])
{
	check(argc==2,"");
	
	//open relevent files
	FILE* fpointer=fopen(argv[1],"r");
	FILE* logger=fopen("ConversionLogs.txt","a");
	check(fpointer!=NULL,"Make sure the extension (eg: .txt) is also mentioned.");
	check(logger!=NULL,"couldn't open the logger, pls check for the file ConversionLogs.txt");
	time_t now;
	time(&now);
	fprintf(logger,"\n\n%s",ctime(&now));
	struct entry* lookup_sheet=NULL;
	lookup_sheet=LoadDictionary(argv[1]);
	check(lookup_sheet!=NULL,"The dictionary is empty");
	int phraseLength=0;
	int LoggerSetting=3;
	char phrase[PHRASEBUFF],abbrev[SHORTBUFF];
	int ans=0,abbrevLength;
	char yes='y';
	while(ans!=6)
	{
		system("cls");
		tweetgen_menu();
		scanf(" %d",&ans);
		switch(ans)
		{
			case 1:	
			printf("\nEnter the phrase:\n");
			scanf(" %[^\n]s",phrase); //MAIN STRING
			phraseLength=str_length(phrase,0);
			debug("phrase=%s",phrase);
			if(phraseLength<140)
			{
				printf("phrase already tweet-size, shorten further?(y/n)");
				scanf(" %c",&yes);
				if(yes=='y')
				{
					ans=tweetgen(phrase,phraseLength,lookup_sheet);
				}
			}else
			{
				ans=tweetgen(phrase,phraseLength,lookup_sheet); //reuse ans to store returned tweet size
			}
			if(ans==-1)    //check for phrase being tweet compatible.If it is, the next stage checks whether it was shortened or not and prints relevant message.
			{
				log_err("tweet could not be shortened any further!\n");
				if(LoggerSetting>1)
				{
					fprintf(logger,"[failed]:%s\n",phrase);
				}
			}else
			if(ans!=phraseLength) //it means that if the size of converted string is smaller than the original, the process of conversion was successful!(and was asked for by the user)
			{
				log_info("tweet conversion successful!\ntweet:%s",phrase);
				if(LoggerSetting!=2)
				{
					fprintf(logger,"[success]:%s\n",phrase);
				}
			}
			if(ans<140)
			{
				fprintf(logger,"[short]:%s\n",phrase);
			}
			ans=0;
			break;
			case 2:
			printf("\nEnter the abbreviation:");
			scanf(" %[^\n]s",abbrev);
			printf("\nEnter the phrase:");
			scanf(" %[^\n]s",phrase);
			abbrevLength=str_length(abbrev,0);
			phraseLength=str_length(phrase,0);
			if(abbrevLength>phraseLength)
			{
				log_err("abbreviation cannot be longer than the phrase!");
			}else
			{
				AddEntry(&lookup_sheet,abbrev,phrase);
				log_info("entry added successfully!");
			}
			break;
			case 3:
			SaveDictionary(&lookup_sheet,argv[1]);
			break;
			case 4:
			printf("\nEnter the dictionary-name:");
			scanf(" %s",phrase);
			struct entry* new=LoadDictionary(phrase);
			if(new==NULL)
			{
				printf("\nbatch load failed!");
			}else
			{
				while(new!=NULL)
				{
					AddEntry(&lookup_sheet,new->word,new->def);
					new=new->next;
				}
			}
			break;
			case 5:
			logger_menu();
			scanf(" %d",&ans);
			if(ans>0&&ans<4)
			{
				LoggerSetting=ans;
			}else
			{
				log_err("invalid logger setting!");
			}
			break;
			case 6:
			break;
			default:
			log_info("invalid option.");
			break;
		}
		// flushes the standard input 
		// (clears the input buffer) 
		while ((getchar()) != '\n');
		printf("\npress any key to continue...");
		getchar();
	}
	
	fclose(fpointer);
	fclose(logger);
	return 0;
error:
	return -1;
}

int tweetgen(char* phrase,int phraseLength,struct entry* trav)
{
	int wordlen,deflen,index,next_index,i=0;
	while(trav!=NULL&&i<ITERATION_LIMITD)
	{			
		deflen=str_length(trav->def,0)-1;
		do
		{
			index=str_find_substring(phrase,trav->def,deflen);
			if(index!=-1)
			{
				wordlen=str_length(trav->word,0)-1;
				next_index=index+deflen;
				debug("index=%d",index);
				debug("word:%s",trav->word);
				debug("def:%s",trav->def);
				debug("string1: %s",phrase);
				str_copy(&phrase[index],trav->word);
				debug("string2: %s",phrase);
				index+=wordlen;
				str_copy(&phrase[index],&phrase[next_index]);
				debug("string3: %s",phrase);
				phraseLength-=(deflen-wordlen);
			}
		}while(index!=-1);
		trav=trav->next;
	}
	if(phraseLength>140)
	{
		return -1;
	}else
	{
		return phraseLength;
	}
}