#include <stdio.h>
#define SIZE 18
#define least 4

void sortFunction(char arr[], int num);
void printCombi(char arr[], int charNum, int tmpSize);
void combiUnit(char arr[], char tmp[], int start, int end, int index, int tmpSize);

int  main(){

	int charNum=0; //Record the position of the StrArray
	char ch; //The input character by loop
	char inputChar[SIZE];  //The StrArray

	while( (ch = getchar())  != '\n'){
			inputChar[charNum] = ch;
			charNum++;
	}
	
	sortFunction(inputChar,charNum);

	for(int i=4;i<=charNum;i++){
		printCombi(inputChar,charNum,i);
	}
	printf("\n");
}

void sortFunction(char arr[], int num){
	int i, j;
	char key; //j is the former, i is the latter, and key will record the latter character.
	for(i=1;i<num;i++){ //i will not exceed (include equal) the SIZE because it is the latter character.
		key = arr[i];
		j = i - 1;

		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void printCombi(char arr[], int charNum, int tmpSize){
	char tmp[tmpSize];
	combiUnit(arr,tmp,0,charNum-1,0,tmpSize);
}

/* arr[] is the Input Array 
   tmp[] is the Temporary array to store current combination 
   start & end is the Staring and Ending indexes in arr[] 
   index is the Current index in data[] 
   tmpSize is the Size of a combination to be printed */
void combiUnit(char arr[], char tmp[], int start, int end, int index, int tmpSize){
	if(index == tmpSize){
		for(int j=0;j<tmpSize;j++)
			printf("%c",tmp[j]);
		printf(",");
		return;
	}

	for(int i=start; (i<=end) && (end-i+1>=tmpSize-index) ;i++){
		tmp[index] = arr[i];
		combiUnit(arr,tmp,i+1,end,index+1,tmpSize);
	}
}



/* //First Edition
int  main(){
	int charNum=0;
	char ch;
	char inputChar[SIZE];
	while( (ch = getchar())  != '\n'){
		if(charNum == 0 || ch > inputChar[charNum-1])
			inputChar[charNum] = ch;
		else if(ch < inputChar[charNum]){
		}
		charNum++;	
	}
	puts(inputChar);
}
*/

/*
void printPermutations(char arr[], int posNum, int charNum){
	int totalNum, nowNum=0;
	totalNum = (int)P(charNum,posNum);

	while(nowNum!=posNum){

		nowNum++;
	}

}
*/