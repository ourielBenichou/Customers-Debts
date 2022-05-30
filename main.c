#ifndef Main
#define Main
#include"ReadPrintFile.h"
#include"SelectQuery.h"

void main()
{
	customerList* head = NULL;
	char* path = "Debts_File.txt",buffer[MAX_LINE];
	FILE* fDebt = fopen(path, "r+t");
	if (fDebt == NULL) {
		do
		{
			printf("\nFile not Exist,Enter a new path :");
			scanf("%s", path);
		} while (fDebt == NULL);
	}
	//covert file to linked list 
	head = readFile(fDebt, head);
	
	//Sort array before print haem
	head = bubbleSort(head);
	//print linked list
	printFile(head);
	/*--------------------------------------------------------Query----------------------------------------------------*/
	
	printMenu();
	do
	{
		printf("\nEnter a choice/record:");
		gets(buffer);
		//ðéúåç äùàéìúä
		getCommand(buffer, fDebt, head);
	} while (strcmp(buffer, "quit"));


	/*----------------------------------------------------End Of Program-----------------------------------------------*/

	printf("\n\n\n\t\t\t\t\t\tGOOD BYE !!!\n\n\n");
	releaseLinkedList(head);
	fclose(fDebt);
}
#endif 
