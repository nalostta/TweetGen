/*
milestone-#10 (main program file!)
author:-manthan shah

a menu-based program to implement a dictionary with the following functionalities:
	add a word and its meaning
	lookup a word
	remove a word from the dictionary
	print all the entries in the dictionary 
	
utility Functions:
OrderedEntry()
NOTE: this program requires milestone-#5!
----------------------------------------------------
nomenclature:
struct entry   => word/entry
struct entry*  => sheet/WordIndex
struct entry** => dictionary/SheetIndex
----------------------------------------------------
*/
#include"milestone-12.h"
#include"milestone-10.h"
#include"milestone-5.h"
#include<conio.h>

int main()
{
	struct entry* list=NULL;
	int answer=0,i;
	char word[WORD_BUFF];
	char def[DEF_BUFF];
	struct entry* trav=list;
	while(answer!=7)
	{
		system("cls");
		DictionaryMenu();
		scanf(" %d",&answer);
		switch(answer)
		{
			case 1: printf("\nEnter the word:");
					scanf(" %s",word);
					printf("\nEnter it's meaning:");
					scanf(" %[^\n]s",def);
					AddEntry(&list,word,def);
					break;
			case 2: printf("\nword to be searched:");
					scanf("%s",word);
					answer=LookUp(&list,word);
					switch(answer)
					{
						case -1:printf("\nThe word does not exist in the Dictionary!\n");
						break;
						default: 
						trav=list;
						for(i=0;i<answer;i++)
						{
							trav=trav->next;
						}
						printf("\nword found at index %d\n%s:%s\n",answer,trav->word,trav->def);
						break;
					}
					break;
			case 3: printf("\nEnter the word to be removed:");
					scanf("%s",word);
					answer=LookUp(&list,word);
					switch(answer)
					{
						case -1:printf("\nThe word does not exist in the Dictionary!\n");
								break;
						default:RemoveEntry(&list,word);
								break;
					}
					break;
			case 4:	PrintDictionary(list);
					break;
			case 5: SaveDictionary(&list,"SavedDictionary.txt");
					break;
			case 6: list=LoadDictionary("SavedDictionary.txt");
					break;
			case 7: //break out of switch and compare in while loop
					break;
			default:printf("\n[error]:invalid command!");
					break;
		}
		while ((getchar()) != '\n');//flush buffer
		printf("\n\n..........press any key to continue");
		getchar();
	}
	return 0;
}
