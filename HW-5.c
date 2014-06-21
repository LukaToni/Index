#include <stdio.h>
#include <stdlib.h>//omogoča malloc
#include <string.h>//strlen(beseda)<dolzina stringa>,strcpy(beseda),strcmp(beseda1,beseda2)<primerja katera beseda je po abecedi prej>

int main()
{
	int len_word;
	int num_word;
	scanf("%d %d",&len_word ,&num_word);
		//naredimo prostor za besedo kjer jo bomo zacasno hranili.
	char *word = malloc((len_word + 1) * sizeof(char));
	char charact;	//za iskanje chara za novo vrstico
		//seznam, ki bo vseboval pointerje na vpisane besede
	char **copy = malloc((num_word) * sizeof(char*));
		//array ki bo seboval podatke o vrsticah besed
	int lines[num_word];
	int count = 0;
	int line = 1;
	
	while(scanf("%s%c",word,&charact) != EOF)
	{
			//besedo shranimo nekam na pomnilnik, tja kaže potem pointer iz tabele copy
		copy[count] = malloc(strlen(word) + 1 * sizeof(char));
		strcpy(copy[count],word);
		lines[count] = line;
			//povečaj število vrstic ke najdes char za novo vrstico
		if (charact == '\n')
		{
			line++;
		}
		count++;
	}
	
	//--------SORTERANJE TABELE----------
	int i, j;
	for(i = 0; i < count - 1; i++)
	{
		int idx_min = i;
		char *tmp;
		int temp;
		for(j = i + 1; j < count ;j++)
		{
			if(strcmp(copy[j], copy[idx_min]) <= 0)
			{
				idx_min=j;
			}
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
	for(z = 0;z < count; z++)
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
			
			//--------SORTIRAMO------------
			for(i = 0;i < msi; i++)
			{
				int smallest = i;
				for(j = i + 1;j <= msi; j++)
				{
					if(minisort[smallest] > minisort[j])
					{
						smallest = j;
					}
				}
				temp = minisort[i];
				minisort[i] = minisort[smallest];
				minisort[smallest] = temp;
			}
			
			//--------IZPISEMO-------------
			int write;
			for(write = 0;write <= msi; write++)
			{
				printf(" %d",minisort[write]);
			}
			printf("\n");
			
			//--------INICIALIZERAMO-------
			int ini;
			for(ini = 0;ini < msi; ini++)
			{
				minisort[ini] = 0;
			}			
			msi = 0;
		}
	}
	return 0;
}
