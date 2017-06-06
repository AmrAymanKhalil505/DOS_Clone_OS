int count_sectors(int ,char* );
int string_compare(char* , char*);
void new_String (char* , char* , int);
void create_String_compare(char*, char*, int ,int*);
void printString_withSize(char* ,int );
void printDigit(int );
void printNumber(int );
int DIV (int ,int);
int MOD (int ,int);
int main ()
{ int view_flag =99;
  int execute_flag=99;
  int i ;
  int j ;
  int k;
  int z;
  int a;
  int c;
  int b;
  int ind ;
  int num_of_char;
  char compare[80];
  char line [80] ;
  char line1 [80] ;
  int done =0;
  char name_of_the_file [7];
  char sectorNumber[2];
  char buffer[13312] ;
  char filename1[80];
  char filename2[80];
  char file1[13312];
  char Directory[512];
  int delete_flag=99;
  char name_of_file[7];
  int number_of_sectors;
  char copy_flag=99;
  int ffound =99;
  int fdone_copying =1;
  int dir_flag=99;
  int create_flag=99;
  int kill_flag=99;
  int sector_numbers ;
  int y;
  int d;
  /*for(i=0;i<79;i++)
  {
    line [i]= 'a';
  }*/

  name_of_the_file[6] = '\0';
  while(1)
  {interrupt(0x21,0,"\n\0",0,0);
    fdone_copying =1;
    ffound =99;
    copy_flag=99;
    delete_flag=99;
//  printString_withSize(line,80);
  done =0;
    view_flag =99;
    execute_flag=99;
    dir_flag =99;
	create_flag = 99;
    interrupt(0x21,0,"Shell>>:\0",0,0);
    interrupt(0x21,1,line,0,0);

    for(i=0;i<80;i++)
    { if(line[i]=='\0'||line[i]==0xa)
      {
        compare[i]='\0';
        break;
      }
      if(line[i]!=' ')
      {
        compare[i]=line[i];
      }
      else
      {
        compare[i]='\0';
      //  interrupt(0x21,0,compare,0,0);
      //  interrupt(0x21,0,"the above is what i have in compare",0,0);
        break;
      }
    }
    //printString_withSize(line,80);
    //interrupt(0x21, 0, compare, 0, 0);
  view_flag = string_compare("view\0" , compare);
  execute_flag = string_compare("execute\0",compare);
  delete_flag=string_compare("delete\0",compare);
  copy_flag = string_compare("copy\0",compare);
  dir_flag = string_compare("dir\0",compare);
  create_flag = string_compare("create\0",compare);
  kill_flag=string_compare("kill\0",compare);
  //interrupt(0x21,0,compare,0,0);
  if(view_flag==0)
      {
        create_String_compare(compare,line,i,&num_of_char);
      //  interrupt(0x21, 0, compare, 0, 0);
        //interrupt(0x21,0,compare,0,0);
        interrupt(0x21, 3,compare, buffer, 0);
      //  interrupt(0x21, 0, buffer, 0, 0);
      interrupt(0x21, 0, buffer, 0, 0);

    }
    else if (execute_flag==0)
      {
        create_String_compare(compare,line,i,&num_of_char);
        interrupt(0x21, 4,compare,0x2000, 0);

      }
    else if (delete_flag==0)
      {
        create_String_compare(compare,line,i,&num_of_char);
        interrupt(0x21,7,compare,0,0);
      }
    else if(copy_flag==0)
      { file1[0]='\0';
        fdone_copying=1;
        create_String_compare(compare,line,i,&num_of_char);
        new_String(compare,filename1,num_of_char);
          // interrupt(0x21, 0, filename1, 0, 0);
          // interrupt(0x21, 0, compare, 0, 0);
        create_String_compare(compare,line,i+num_of_char,&num_of_char);
        new_String(compare,filename2,num_of_char);
        // interrupt(0x21, 0, filename2, 0, 0);
        // interrupt(0x21, 0, compare, 0, 0);
        interrupt(0x21,3,filename1,file1,0);
        //interrupt(0x21, 0, file1, 0, 0);
        if(file1[0]!='\0');
        {
          interrupt(0x21,2,Directory,2,0);
          for(i =0;i<512;i+= 32)
        	{
        		for( ind=0;ind<6;ind++)
        		{
              if(Directory[i+ind]!= 0x00)
        			name_of_file[ind] =	Directory[i+ind];
        			else
        			name_of_file[ind]='\0';
        		}
            ffound=string_compare(name_of_file,filename1);
            if(ffound==0)
            {fdone_copying=0;
                number_of_sectors=count_sectors(i,Directory);
                interrupt(0x21,8,filename2,file1,number_of_sectors);
            }

          }
          if(fdone_copying!=0)
          {
            interrupt(0x21,0,"file no found\n\0",0,0);
          }
        }
      }
      else if (dir_flag == 0)
       {interrupt(0x21,2,Directory,2,0);
             for (k =0 ; k<512;k=k+32)
             {
                    if (Directory[k] != 0x00)
                    {
                    	for( y=0 ; y<6 ; y++)
                         {
                                   name_of_the_file[y] = Directory[k+y];
                         }

                             interrupt(0x21,0,name_of_the_file,0,0);
                             interrupt(0x21,0," : \0",0,0);
                             interrupt(0x21,0,"The number of sectors are : \0",0,0);
                             sector_numbers=0;
                             for (z=6;z<32;z++)// we need to think of now to print the hexa numbers or converting them to decimal TODO
                             {
                              if(Directory[k+z]==0x00)
                              break;
                              sector_numbers++;
                             }

                             printNumber(sector_numbers);
                             interrupt(0x21,0,"\n\0",0,0);
                    }
             }

       }
	   else if (create_flag == 0)
	   {
		   create_String_compare(compare,line,i,&num_of_char);
		   c = 0;
		   a = 0;
		   number_of_sectors = 0;

		   while(1)
		   {
		   		 for(d = 0; d<80; d++){
		   			line1[d] = 0xd;
		   		 }
				 interrupt(0x21,0,">:\0",0,0);
				 interrupt(0x21,1,line1,0,0);
				 if ((line1[0] == "\n") || (line1[0] == 0xa) || (line1[0] == 0xd) || (line1[0] == 0x0) || (line1[0] == "\0"))
				 {
					 break;
				 }
				 for(a = 0; line1[a] != 0xd; a++)
				 {
					 buffer[c+a] = line1[a];
				 }
				 c += a-2;
				 buffer[c]=0x2f;

				 c++;
		   }
		   //printString_withSize(buffer,15);
		   for(b = 0;b<c+1;b=b+512)
		   {
			   number_of_sectors++;
		   }
		   interrupt(0x21,8,compare,buffer,number_of_sectors);
	   }
     else if(kill_flag)
     {
       char number_that_i_will_make_it_int = line[i+1];
       int the_int = number_that_i_will_make_it_int-'0';
       interrupt(0x21,9,the_int,0,0);
     }
    else
      {
        interrupt(0x21,0,"bad command\n\0",0,0);
      }
      //interrupt(0x21,0,"\n\0",0,0);
  }
  return 0;
}
void new_String (char* new_S, char* buffer , int S_size)
{ int i;
  for(i=0;i<S_size;i++)
  {  buffer[i]= new_S[i];
  }


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
void create_String_compare(char* compare, char* line , int i,int* num_of_char)
{
  int j ;
  i++;
 //printDigit(i);
  for(j = i ;j<80;j++)
  {
    // if(line[j]==' ')
    // {
    //   interrupt(0x21, 0, "space\n\0", 0, 0);
    // }
    // if(line[j]=='\0')
    // {
    //   interrupt(0x21, 0, "slash zero\n\0", 0, 0);
    // }
    // if(line[j]==0xa)
    // {
    //   interrupt(0x21, 0, "zero x a \n\0", 0, 0);
    // }

    if(line[j]!=' '&& line[j]!='\0'&& line[j]!=0xa)
    {//interrupt(0x21, 0, "if\n\0", 0, 0);
      compare[j-i]=line[j];

    }
    else
    {//interrupt(0x21, 0, "else\n\0", 0, 0);
      compare[j-i]='\0';

      break;
    }


  }

  *(num_of_char)=j-i+1;
}

// void new_String1 (char* new_S, char* buffer , int S_size)
// { int i;
//   for(i=0;i<S_size;i++)
//   {
//     buffer[i]= new_S[i];
//   }
//
// }
int count_sectors(int i,char* Directory)
{int ind ;
  int count=0;
  for(ind =0;ind<26;i++)
  {if(Directory[ind+i]!=0x00)
    count ++;
    else
    break;
  }
  return count ;
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
void printDigit(int x)
{
  char out_x [2] ;
  /*if(x == 1)
  return '1';
  if(x == 2)
  return '2';
  if(x == 3)
  return '3';
  if(x == 4)
  return '4';
  if(x == 0)
  return '0';
  if(x == 0)
  return '0';
  if(x == 0)
  return '0';if(x == 0)
  return '0';if(x == 0)
  return '0';if(x == 0)
  return '0';if(x == 0)
  return '0';*/
  out_x[0]='0'+x;
  out_x[1]='\0';
  interrupt(0x21,0,out_x,0,0);
}
void printNumber(int x)
{   /*int i ;
    char Digit_In_String[5];
    for(i=0;i<2;i++)
    {
      Digit_In_String[i]='0';
    }

    for(i=0;i<2;i++);
    {
      Digit_In_String[2-i]=MOD(x,10)+'0';
      x=DIV(x,10);
    }
      Digit_In_String[3]=' ' ;
    Digit_In_String[4]='\0';
    interrupt(0x21,0,Digit_In_String,0,0);
  */
  if(x==0){interrupt(0x21,0,"0\0",0,0);}
  if(x==1){interrupt(0x21,0,"1\0",0,0);}
  if(x==2){interrupt(0x21,0,"2\0",0,0);}
  if(x==3){interrupt(0x21,0,"3\0",0,0);}
  if(x==4){interrupt(0x21,0,"4\0",0,0);}
  if(x==5){interrupt(0x21,0,"5\0",0,0);}
  if(x==6){interrupt(0x21,0,"6\0",0,0);}
  if(x==7){interrupt(0x21,0,"7\0",0,0);}
  if(x==8){interrupt(0x21,0,"8\0",0,0);}
  if(x==9){interrupt(0x21,0,"9\0",0,0);}

  if(x==10){interrupt(0x21,0,"10\0",0,0);}
  if(x==11){interrupt(0x21,0,"11\0",0,0);}
  if(x==12){interrupt(0x21,0,"12\0",0,0);}
  if(x==13){interrupt(0x21,0,"13\0",0,0);}
  if(x==14){interrupt(0x21,0,"14\0",0,0);}
  if(x==15){interrupt(0x21,0,"15\0",0,0);}
  if(x==16){interrupt(0x21,0,"16\0",0,0);}
  if(x==17){interrupt(0x21,0,"17\0",0,0);}
  if(x==18){interrupt(0x21,0,"18\0",0,0);}
  if(x==19){interrupt(0x21,0,"19\0",0,0);}

  if(x==20){interrupt(0x21,0,"20\0",0,0);}
  if(x==21){interrupt(0x21,0,"21\0",0,0);}
  if(x==22){interrupt(0x21,0,"22\0",0,0);}
  if(x==23){interrupt(0x21,0,"23\0",0,0);}
  if(x==24){interrupt(0x21,0,"24\0",0,0);}
  if(x==25){interrupt(0x21,0,"25\0",0,0);}
  if(x==26){interrupt(0x21,0,"26\0",0,0);}
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
	{
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
