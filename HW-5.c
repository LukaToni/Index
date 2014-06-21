#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int len_word;
	int num_word;
	scanf("%d %d",&len_word ,&num_word);
	
	char *word = malloc((len_word + 1) * sizeof(char));//create a place where we will temporary stored our word
	char charact;	//for searching char for new line
	
	char **copy = malloc((num_word) * sizeof(char*)); //list which will contain ponters on writed words
		
	int lines[num_word]; //data of lines of words
	int count = 0;
	int line = 1;
	
	while(scanf("%s %c",word, &charact) != EOF)
	{
		copy[count] = malloc(strlen(word) + 1 * sizeof(char));
		strcpy(copy[count], word);
		lines[count] = line;
		
		if (charact == '\n') //in new line add line
			line++;
		
		count++;
	}
	
	//--------SORT TABLE----------//
	int i, j;
	for(i = 0; i < count - 1; i++)
	{
		int idx_min = i;
		char *tmp;
		int temp;
		for(j = i + 1; j < count ;j++)
		{
			if(strcmp(copy[j], copy[idx_min]) <= 0)
				idx_min=j;
		}
		tmp = copy[i];
		copy[i] = copy[idx_min];
		copy[idx_min] = tmp;
		
		temp = lines[i];
		lines[i] = lines[idx_min];
		lines[idx_min] = temp;
	}
	
	int msi = 0;
	int minisort[count];
	int z;
	for(z = 0; z < count; z++)
	{
		minisort[msi] = lines[z];
		int temp;
		
		if(z + 1 < count && strcmp(copy[z],copy[z + 1]) == 0)
		{
			msi++;
			minisort[msi] = lines[z + 1];
		}
		
		else
		{
			printf("%s",copy[z]);
			
			//--------SORT------------//
			for(i = 0;i < msi; i++)
			{
				int smallest = i;
				for(j = i + 1;j <= msi; j++)
				{
					if(minisort[smallest] > minisort[j])
						smallest = j;
				}
				temp = minisort[i];
				minisort[i] = minisort[smallest];
				minisort[smallest] = temp;
			}
			
			//--------PRINT-------------//
			int write;
			for(write = 0;write <= msi; write++)
			{
				printf(" %d",minisort[write]);
			}
			printf("\n");
			
			//--------INICIALIZATION-------//
			int ini;
			for(ini = 0; ini < msi; ini++)
				minisort[ini] = 0;
						
			msi = 0;
		}
	}
	return 0;
}
