void printString(char*);
void readString(char*);
void readSector(char*,int);
int MOD(int ,int );
int DIV(int ,int );
void handleInterrupt21(int, int, int, int);
void readString(char*,int);
void readFile(char*,char* );
void executeProgram(char*);
void terminate();
void roll_back (int );
void writeSector(char* ,int );
void deleteFile(char* );
void writeFile(char*, char*,int);
void new_String(char*,char*,int);
void printString_withSize(char* ,int );
void handleTimerInterrupt(int,int);
void returnFromTimer(int,int);
void printNumber(int );
void kill(int );
void printInt(int );
//void makeInterrupt21();
int currentProcess;
int arr_activity [8];
int arr_sp [8];
int tic =0;
int main(){

/*char line[80];



int i ;
char buffer[512];
line [80]='\0' ;
for(i=0;i<79;i++)
{
line [i]= 'a';

}
makeInterrupt21();
interrupt(0x21,0,"Say hi to the world \n \0",0,0);
interrupt(0x21,1,line,0,0);
interrupt(0x21,0,line,0,0);
interrupt(0x21,2,buffer,30,0);
interrupt(0x21,0,buffer,0,0);

	while(1)
	{

	}
return 0*/
/*char line [80];
char buffer[13312];/*this is the maximum size of a file*/
/*makeInterrupt21();
interrupt(0x21, 4, "shell\0", 0x2000, 0);
while(1);
return 0;*/
/*char buffer[13312];
char DiskMap[513];
char Directory[513];
int i;
makeInterrupt21();
interrupt(0x21, 2,	DiskMap	,1,0);
interrupt(0x21, 2,	Directory	,2,0);
DiskMap[513]='\0';
Directory[513]='\0';
for(i=0;i<512;i++)
{
	if(DiskMap[i]==0x00)
		{
			DiskMap[i]=0x23 ;

		}

		if(Directory[i]==0x00)
			{
				Directory[i]=0x24 ;
			}
			if(Directory[i]==0xFF)
				{
					Directory[i]=0x25 ;
				}

}
interrupt(0x21 , 0, Directory,0,0);

interrupt(0x21 , 0, DiskMap,0,0);

/*interrupt(0x21, 7, "messag\0", 0, 0); //delete messag
interrupt(0x21, 3, "messag\0", buffer, 0); // try to read messag
interrupt(0x21, 0, buffer, 0, 0); //print out the contents of buffer


interrupt(0x21, 2,	DiskMap	,1,0);
interrupt(0x21, 2,	Directory	,2,0);
DiskMap[513]='\0';
Directory[513]='\0';
interrupt(0x21 , 0, DiskMap,0,0);
interrupt(0x21 , 0, Directory,0,0);*/
/*
int i=0;
char buffer1[13312];
char buffer2[13312];
char Directory[512];
char DiskMap[512];
char name [7];
new_String(name , "testWa\0",7);

buffer2[0]='h'; buffer2[1]='e'; buffer2[2]='l'; buffer2[3]='l';
buffer2[4]='o';
for(i=5; i<13312; i++) buffer2[i]=0x0;
makeInterrupt21();

interrupt(0x21,8, "testWa\0", buffer2, 1); //write file testW
interrupt(0x21,3, "testWa\0", buffer1, 0); //read file testW
interrupt(0x21,0, buffer1, 0, 0); // print out contents of testW*/
//readSector(Directory,2);
//printString_withSize(Directory,512);*/


/*char line [80];
char buffer[13312];/*this is the maximum size of a file*/
//makeInterrupt21();
/*interrupt(0x21, 3, "messag\0", buffer, 0);
interrupt(0x21, 0, buffer, 0, 0);
interrupt(0x21, 0, "\n\0", 0, 0);
interrupt(0x21, 3, "tstprg\0", buffer, 0);
interrupt(0x21, 0, buffer, 0, 0);
interrupt(0x21, 0, "\n\0", 0, 0);
interrupt(0x21, 3, "shell\0", buffer, 0);
interrupt(0x21, 0, buffer, 0, 0);
interrupt(0x21, 0, "\n\0", 0, 0);*/
//interrupt(0x21, 4, "shell\0", 0x2000, 0);
int i;
setKernelDataSegment();
tic=0;
for(i=0;i<8;i++)
{
arr_activity[i]=0;
arr_sp[i]=0xFF00;
}currentProcess=0;
restoreDataSegment();
makeTimerInterrupt();
makeInterrupt21();

//printString("this game was\n");


//interrupt(0x21, 4, "shell\0", 0, 0);
interrupt(0x21, 4, "shell\0", 0, 0);interrupt(0x21, 4, "shell\0", 0, 0);kill(0);
//interrupt(0x21, 4, "shell\0", 0, 0);

/*
interrupt(0x21, 4, "hello1\0", 0, 0);
interrupt(0x21, 4, "hello2\0", 0, 0);
//printString("wp\n");
*/

while(1);
}
void printString_withSize(char*c, int S_size ){
	char x;
	int i;
	int numberofbackspaces ;
	numberofbackspaces= 0;
	for(i=0;i<S_size;i++){
		numberofbackspaces++;
		{
			x = *c;
			interrupt(0x10,0xE*256+x,0,0,0);
			c++;
		}

	}

}
void printString(char*c){
	char x;

	int numberofbackspaces ;
	numberofbackspaces= 0;
	while(1){
		numberofbackspaces++;
		if(*c=='\0')
			break;
		else if (*c==0xd||*c=='\n'||*c=='\r')
		{
			x = *c;
			interrupt(0x10,0xE*256+x,0,0,0);

			//roll_back(numberofbackspaces);
			//numberofbackspaces=0;
			break;
		}
		else
		{
			x = *c;
			interrupt(0x10,0xE*256+x,0,0,0);
			c++;
		}

	}

}

void roll_back (int c )
{
	while(c--)
	{
		interrupt(0x10,0xe*256+0x8,0,0,0);
	}

}

void readString(char*c){
int x;
int Sizeofthebuffer;
//char arr [80];
int i ;
int thisChar;
//int c1;
//int c2;



/*for( i =0;i<79;i++)
{
	if(*(c+i)=='\0')
	{
		printString("Error \0");
		break;
	}
}*/
x=0;


while(1){
int MyChar =interrupt(0x16,0,0,0,0);   // read from keyboard
int numberofbackspaces ;
	numberofbackspaces= 0;
if(MyChar==0xd){// Enter

	*(c)=0xa;
	interrupt(0x10,0xE*256+0xa,0,0,0);
	*(c+1)=0x0;
	interrupt(0x10,0xE*256+0x0,0,0,0);

	//while(numberofbackspaces--)
	//{
//	interrupt(0x10,0xe*256+0x8,0,0,0);
//	}

	break;

}
else if(MyChar==0x8){// backspace <--
	if(x!=0)
	{	numberofbackspaces--;
	 *c=0x0;
	 	 interrupt(0x10,0xe*256+0x8,0,0,0);
         interrupt(0x10,0xe*256+0x0,0,0,0);
         c--;
      *c=0x0;
         interrupt(0x10,0xe*256+0x8,0,0,0);
		 x--;
	}

}

else{
interrupt(0x10,0xE*256+MyChar,0,0,0); // print it on the screen
*c=MyChar;							//store ;
x++;
c++;
numberofbackspaces++;
}
}

}

void readSector(char* buffer,int sector)
{
int relative_sector;
int head;
int track;

relative_sector = MOD(sector,18)+1;
head = MOD(DIV(sector,18),2);
track = DIV(sector ,36);
interrupt(0x13,2*256+1,buffer,track*256 +relative_sector,head*256 +0);

}
void writeSector(char* buffer,int sector)
{
int relative_sector;
int head;
int track;

relative_sector = MOD(sector,18)+1;
head = MOD(DIV(sector,18),2);
track = DIV(sector ,36);
interrupt(0x13,3*256+1,buffer,track*256 +relative_sector,head*256 +0);

}
/*
void executeProgram(char* name, int segment){
int i;
char buffer[13312];
readFile(name,buffer);


for(i=0;i<=13312;i++){

    putInMemory (segment,i,buffer[i]);

}

 launchProgram(segment);

}*/

void executeProgram(char* name){
int i;
int j;
char buffer[13312];

readFile(name,buffer);
setKernelDataSegment();
for(i=0;i<8;i++)
	{
		if(arr_activity[i]==0)
		{

			arr_activity[i]=1;
			break;
		}

	}
restoreDataSegment();

for(j=0;j<=13312;j++){

			putInMemory ((i+2)*0x1000,j,buffer[j]);

	}
initializeProgram((i+2)*0x1000);


}

/*
for(j=0;j<8;j++)
{
	if(arr_activity[j]==0)
	{ arr_sp[j]=0xFF00;

		for(i=0;i<=13312;i++){

					putInMemory (j*0x1000+0x2000,i,buffer[i]);

			}
setKernelDataSegment();
		arr_activity[j]=1;
restoreDataSegment();
/*setKernelDataSegment();
currentProcess=j;
restoreDataSegment();
*/

		/*initializeProgram(j*0x1000+0x2000);
		break;
	}
}*/


void deleteFile(char* fname)
{
	char name_of_file [7];
	char DiskMap [512];
	char Directory[512];
	int place ;
	int ind =0;
	int i =0;
	int j =0;
	int k =0;
	int ffound;

	readSector(DiskMap,  1);
	readSector(Directory,2);
	for(i =0;i<512;i+= 32)
	{
		for( ind=0;ind<6;ind++)
		{	if(Directory[i+ind]!= 0x00)
			name_of_file[ind] =	Directory[i+ind];
			else
			name_of_file[ind]='\0';
		}
		 ffound = string_compare(name_of_file,fname);
		 if(ffound==0)
		 {//interrupt(0x21,0,"here\0",0,0);
			 	Directory[i]=0x00;
				for(ind = 6 ; ind<32&& Directory[ind]!=0x00;ind++)
				{
					place = Directory[ind];
					DiskMap[place]=0x00;
				}
				writeSector(DiskMap,  1);
				writeSector(Directory,2);
				return ;
		 }

	}

		printString("file is not found\n\0");

}
void writeFile(char* name, char* buffer, int secNum)
{
	int j;
	int k ;
	char DiskMap [512];
	char Directory[512];
	char buffer512[512];
	int i;
	int ind;
	int freeSectors;
	char place;
	int ffound=0;
	freeSectors=0;
	readSector(DiskMap,  1);
	readSector(Directory,2);
	for(i=0;i<512;i++) //checking the freeSectors
	{
		if(DiskMap[i]==0x00)
		{
			freeSectors++;
		}
	}
	if(freeSectors>=secNum)
	{
		for(i =0;i<512;i+= 32)
		{
			if(Directory[i]==0x00)//if the first byte of the name is 0x00
			{					ffound=1;						// put the name there
				for(ind =0;ind<6;ind++)
				{
					if(name[ind]!='\0')
					Directory[i+ind]=name[ind];
					else
					break;
				}
				for(ind = ind ;ind<6;ind++)
				{
					Directory[i+ind]=0x00;//if it is smaller than 6 chars put zeros for the rest
				}
				//printString_withSize(Directory,512);
				for(ind =0;ind<secNum;ind++)// for each sectornumber
				{
					for(j=0;j<512;j++)//search for empty place in the DiskMap
					{
						if(DiskMap[j]==0x00)// when found
						{
								DiskMap[j]=0xFF;// make it not empty
								place =j;
								Directory[i+ind+6]=place;//put the number of the empty sector we found in the DiskMap in the Directory
								for(k=0;k<512;k++)// copy 512 byte
								{
									buffer512[k]=buffer[k+ind*512];
								}
								writeSector(buffer512,j);// write them in the memory
								break;
						}
					}
				//	printString_withSize(Directory,512);
				}
				writeSector(DiskMap,1);
				writeSector(Directory,2);
				if(ffound==0)
				printString("you can only put 16 files on your floppy\n\0");

				return ;
			}
	}

}
else
	{
		printString("no empty space\n\0");
		return;
	}
}
void kill (int pro)
{
	setKernelDataSegment();
		arr_activity[pro]=0;
	restoreDataSegment();

}
void readFile(char* fname,char* buffer){// buffer we put in it a file
char name_of_file [7] ;// file name from 6 charaters
int  array_of_sectors[26];// 26 sector
int ffound;// boolean if found
char Mybuffer[512];// we load in it the Directory
int i =0;
int j =0;
int k =0;
int ind =0;
int sector_Place ;
char Mybuffer2[512];
readSector(Mybuffer,2);
name_of_file[6]='\0';
fname[6]='\0';
for(i =0;i<512;i+= 32)
{
	for( ind=0;ind<6;ind++)
	{	if(Mybuffer[i+ind]!= 0x00)
		name_of_file[ind] = Mybuffer[i+ind];
		else
		name_of_file[ind]='\0';
	}

//  printString(name_of_file);
//	printString("\n\0");S
//printString(fname);
//printString(name_of_file);
//printString("\n\0");
	 ffound = string_compare(name_of_file,fname);
	 if(ffound==0)
	 {
		 for(j=0;j<26;j++)
		 {
			 	sector_Place=Mybuffer[i+j+6];// j=0 i+6
				readSector(Mybuffer2,sector_Place);
				for(k=0;k<512;k++)
				{
					buffer[j*512+k]=Mybuffer2[k];
				}
		 }
		 buffer[13311]='\0';
		 return;
	 }

}
printString("no such file\0");
return;
}

int string_compare(char* str1, char* str2)
{
    int c=0;

    while(str1[c]==str2[c])
    {
        if(str1[c]=='\0'||str2[c]=='\0')
            break;
        c++;
    }
    if(str1[c]=='\0' && str2[c]=='\0')
        return 0;
    else
        return -1;
}

int MOD (int n , int m)

{
	int IntegerDev ;
	int outputMod;
	IntegerDev=DIV(n,m);
	outputMod=n-m*IntegerDev;
	return outputMod;

}
int DIV (int n , int m  )
{	int i;	// index
	int out ;// output
	int is_one_negative; //if any of the numbers is negative but not the others

	i=0;	// index
	out = 0;// output
	 is_one_negative=0;
	if(n<0&&m<0)
	{
		n=-1*n;
		m=-1*m;	// if both of them is negative it doesn't matter as it has the same output as the possive
	}
	else if(n<0)
		{	n=-1*n;
			is_one_negative =1;
		}
	else if(m<0)
		{
			m=-1*m;
			is_one_negative = 1;// one of them is negative so the answer is -1 * the possive answer
		}

	if(n<m)
	{
		return 0;
	}
	if(n==0)
	{
		return 0;
	}
	if(m==0)
	{ printString("Math Error \0");
 		return 0;
	}
	if(n==m)
	{
		out= 1;
	}

	for(i=0;i<=n;i++)
	{
		if(i*m<=n)
		{
			out = i;
		}
	}
	if(is_one_negative )
	return -1*out;
	else
	return out;
}
void terminate()
{	setKernelDataSegment();
	arr_activity[currentProcess]=0;
//	arr_sp[currentProcess]=0xff00;
	while(1);
}
/*
void makeInterrupt21()
{
	interrupt(0x21,0,0,0,0);
}
*/
void new_String (char* new_S, char* buffer , int S_size)
{ int i;
  for(i=0;i<S_size;i++)
  {
    buffer[i]= new_S[i];
  }

}
void handleInterrupt21(int AX,int BX, int CX, int DX){


if(AX==0){
	printString(BX);

}

else if(AX==1){
	readString(BX);
}

else if(AX==2){
	readSector(BX,CX);
}

else if(AX==3){
	readFile(BX,CX);
}

else if(AX==4){
	executeProgram(BX);
}
else if(AX==5)
{
	terminate();
}
else if(AX==6)
{
	writeSector(BX,CX);
}
else if(AX==7)
{
	deleteFile(BX);
}
else if(AX==8)
{
	writeFile(BX,CX,DX);
}
else if(AX==9)
{
	kill(BX);
}
else
{
	printString("Error\n\0");
}

}
void handleTimerInterrupt(int segment, int sp)
{int i;int new_segment ;int new_sp;int flag_more_than_100;
	int changed = 0;

	//printString("tic\n");
//printInt(DIV(segment ,0x1000)-2);
	setKernelDataSegment();
		tic++;

	flag_more_than_100=(tic>99);
	restoreDataSegment();
//if(segment==(DIV(segment,0x1000)-2))
	if(flag_more_than_100)
	{
setKernelDataSegment();
		tic =0;
		arr_sp[currentProcess]=sp;


	for(i=currentProcess+1;i<8;i++)
	{
		if(arr_activity[i]==1)
		{
			currentProcess=i;
			changed=1;
			//returnFromTimer((i+2)*0x1000,arr_sp[i]);return;
			new_segment=(i+2)*0x1000;
			new_sp=arr_sp[i];
			break;
		}
	}

	for(i=0;i<currentProcess&&!changed;i++)
	{
		if(arr_activity[i]==1)
		{


			currentProcess=i;
			changed=1;
			//returnFromTimer((i+2)*0x1000,arr_sp[i]);return;
			new_segment=(i+2)*0x1000;
			new_sp=arr_sp[i];
			break;
		}
	}

restoreDataSegment();
		if(changed)
		{
	//		printString("the worst code ever\n");
	//	printInt(new_segment);
			returnFromTimer(new_segment,new_sp);return;
		}
		else
		{
			returnFromTimer(segment,sp);return;
		}
}
returnFromTimer(segment,sp);return;

}
/*	int i;

//printString("tic\n");
setKernelDataSegment();
tic++;
restoreDataSegment();
//printNumber(tic);
//printString(" \0");
	if(tic>99)
	{//printString("tic\n");


			arr_sp[currentProcess]=sp;
			tic=0;

		for(i=MOD(currentProcess+1,8);1;i=MOD(i+1,8))
		{
			if(arr_activity[i]==1)
			{

				currentProcess=i;

				returnFromTimer((i+2)*1000,arr_sp[i]);
				break;
			}
			else if(i==currentProcess)
			{
					returnFromTimer(segment,sp);
					break;
			}
		}
	}
		returnFromTimer(segment,sp);

}*/

void printInt(int i)
{
	//holds an array to print
	char toPrint[2];
	//a counter for the current power of 10
	int power = 1;

	//add a null terminator to the end of our printing array
	toPrint[1] = 0x0;

	//if it is negative, print a '-' sign first
	if(i < 0) {
		//ASCII for '-'
		toPrint[0] = 0x2D;
		printString(toPrint);
		//reverse the value
		i = -i;
	}

	//find the greatest power of 10 not greater than i
	while (power <= i/10) {
		power = power * 10;
	}

	//keep going down by powers of 10 to get the left most digit at a time
	for (power; power >= 1; power = power / 10) {
		//integer division will give the left most digit
		int n = i / power;

		//get its ASCII value
		if (n == 0)
			toPrint[0] = 0x30;
		else if (n == 1)
			toPrint[0] = 0x31;
		else if (n == 2)
			toPrint[0] = 0x32;
		else if (n == 3)
			toPrint[0] = 0x33;
		else if (n == 4)
			toPrint[0] = 0x34;
		else if (n == 5)
			toPrint[0] = 0x35;
		else if (n == 6)
			toPrint[0] = 0x36;
		else if (n == 7)
			toPrint[0] = 0x37;
		else if (n == 8)
			toPrint[0] = 0x38;
		else if (n == 9)
			toPrint[0] = 0x39;
		//print it
		printString(toPrint);
		//get the remainder
		i = MOD(i, power);
	}
}

/*
 * Clear the screen and place the cursor at the top left.
 */
