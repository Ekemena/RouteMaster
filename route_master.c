#include<stdio.h>
#include<string.h>
char a[20][20]={"B.K.Pudur","V.L.Mills","E.D.Pirivu","Aparna","Kuniyamuthur","Aathupaalam","Ukkadam","Townhall","Railway station","Gandhipuram"};
int from,to,ticket_count=0;
char in_user[100];

    struct user
    {
        char name[100];
        //char dob[10]
        //int mobile;
        int avbalance;
        char gender[10];
        //char from[100];
        //char to[100];
        char username[100];
        char password[100];


    };


    struct ticket
    {	int flag;
        int price;
        char from[100];
        char to[100];
        int serialno;



    };


    struct bus
    {
        int seatavb;
        int busno;
        int totalseats;
        struct ticket tickets[60];
        char from[20];
        char to[20];
        float time;

    }bus_obj[48];


int abs(int x){
	if(x<0)
		return -x;
	else
		return x;
}
int checkp(char* a);
void signin();
//function to sign up
/*
This module will create new user account and add it to the database.
Function : signup()
Return value : Null

*/
void signup()
{
    char user[100],check[30]="null",pass[30];
    int rs,flag=0;
    FILE *ptr;
    ptr=fopen("user.dat","a+");


        fscanf(ptr,"%s\n",check);
        if(strcmp(check,"null")!=0)
        {
       x:
       printf("Enter the username:\n");
       scanf("%s",user);


       do
       {
            if(strcmp(user,check)==0)
        {
            printf("Oh sorry! Somebody took that!,try again by different name:)\n");
            flag=1;
            goto x;
       }
       } while (fscanf(ptr,"%s\n",check)!=EOF);
       p1:
       printf("Enter the secret code:\n");
       scanf("%s",pass);
       rs=checkp(pass);
             if(rs<3)
              goto p1;

        fprintf(ptr,"\n%s %s",user,pass);
        }
        else
        {
             printf("Enter the username:\n");
             scanf("%s",user);
             p:
             printf("Enter the secret code:\n");
             scanf("%s",pass);
             rs=checkp(pass);
             if(rs<3)
              goto p;
             fprintf(ptr,"%s %s",user,pass);
        }


       fclose(ptr);
       printf("Account created please Login :) !\n");
       signin();


 }
 //function to check password strength
 /*This module validate the password criteria :
Funcion name: pass_validate(String)
Return value: 
    1->Password Accepted
    0->Password not Accepted
*/
int checkp(char* a)
{
  int num_flag=0,A_flag=0,a_flag=0,spl_flag=0,signal;
  char b[200];
   for(int i=0;a[i]!='\0';i++)
   {
     b[i]=(int)a[i];
     if(b[i]>=48 && b[i]<=57)
      num_flag=1;
     if(b[i]>=65 && b[i]<=97)
      A_flag=1;
     if(b[i]>=65 && b[i]<=89)
      A_flag=1;
     if(b[i]>=97 && b[i]<=122)
      a_flag=1;
     if(a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'||a[i]=='^'||a[i]=='&'||a[i]=='*'||a[i]=='('||a[i]==')'||a[i]=='-'||a[i]=='+')
      spl_flag=1;
  }
  signal=num_flag+A_flag+a_flag+spl_flag;
  if(signal==4)
    printf("woW,Strong Password\n");
  if(signal==3)
    printf("oK,Moderate Password\n");
  if(signal<3)
    printf("No its too Weak password,we cannot accept that:(\n");
  return signal;
}
//function to signin
/*
This module will signin the user, who are all already signedup.
Function name: signin()
Return Value: NULL

*/
void signin()
{
    char in_pass[100],in_check[30]={"null"},in_fuser[30],in_fpass[30];

    int i=0,flag=0;

    FILE *ptr;
  x:   printf("Enter the username:\n");
        scanf("%s",in_user);
        ptr=fopen("user.dat","a+");

       while(fscanf(ptr,"%s %s\n",in_fuser,in_fpass)!=EOF)
       {
           if(strcmp(in_fuser,in_user)==0)
             {
                y: printf("Enter your secret code:\n");
                scanf("%s",in_pass);
                 if(strcmp(in_fpass,in_pass)==0)
                 {

                     flag=1;
                     printf("You are Logged in :)\n ..........Welcome to ROUTE MASTER.........\n\n");
                     break;
                 }
                 else
                 {
                     printf("No,its not your secret code,Tryagain:(\n");
                     goto y;
                 }

             }

       }fclose(ptr);

       if(flag==0)
       {
           printf("First create your account or check the Spelling:(\n");
           goto x;
       }

    fclose(ptr);


}


void login()
{
    printf("                  ***Route Master***\n\n\n              Enter a choice\n          1. I don't have an account..Help me to create one.\n          2. I am an Existing user let me sign in.\n");
    char choice;
    int n=0;
 

    l:
    scanf("%c",&choice);getchar();

    if (choice=='1')
    {
        
    }
    else if(choice=='2')
    {
        
    }
    else
    {
        printf("I think you hit a wrong Button:(\n");
        printf("Please Hit Again:)\n");
        goto l;
    }
    
    
    switch (choice)
    {
    case '1':
        signup();
        break;
    case '2':
        signin();
        break;

    }

}

    void print_ticket(struct ticket t1)
   {
   	printf("\n");
	printf("E-Ticket : ");
	printf("\n");
	printf("\t\t\t\t\t\t************************************\n");
	printf("\t\t\t\t\t\t***********Ticket Details***********\n");
	printf("\t\t\t\t\t\t     UserName : %s\n",in_user);
	printf("\t\t\t\t\t\t     From     : %s\n",t1.from);
	printf("\t\t\t\t\t\t     To       : %s\n",t1.to);
	printf("\t\t\t\t\t\t     Price    :RS.%d\n",t1.price);
	printf("\t\t\t\t\t\t***********Ticket Booked***********\n");
	printf("\t\t\t\t\t\t***********************************\n");
   }

int ticket_price(int from,int to)
{
  int i,temp=0,p=5;
  temp=abs(from-to);
  if(temp==1)
   return p;
  if(temp>1)
  {
    for(i=0;i<temp-1;i++)
     {
	p=p+2;
     }
    return p;
  }
return 0;
}
void void_fromto()
{
int loc_count=0;
printf("Choose the Boarding Stop: \n");
for(int i=0;i<a[i][0]!='\0';i++)
{
printf("%d.%s\n",i+1,a[i]);
loc_count=loc_count+1;
}
do
{
scanf("%d",&from);
if(from>loc_count || from<1)
{
 printf("Can't get that! Please select from given location:)\n");
 printf("Choose Boarding Stop: \n");
}

}while(from>loc_count || from<1);

printf("Choose the destination stop: \n");
for(int i=0,k=1	;i<a[i][0]!='\0';i++)
{
  if(i!=from-1)
{
printf("%d.%s\n",i+1,a[i]);

}
}
do
{
scanf("%d",&to);
if(to>loc_count || to<1 || to==from)
{
 printf("Can't get that! Please select from given location:)\n");
 printf("Choose the Destination stop: \n");
}

}while(to>loc_count || to<1 || to==from);
}
int find(int n,char from_input[],int ia)
{	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i],from_input)==0)
		{
		flag=1;
		break;
		}
	}
	if (flag==1)
	return 1;
	else
	return 0;
}

void Buses_in_From_To_Destination(char from_input[],char dest_input[],float time1)
{
    printf("The Available Buses Are:\n");
	printf("__________________________________________________________________________________\n");
    printf("|Bus_No\t|Start_Location\t|Destionation_location\t|Seats_Available  |Arrival_Time |\n");
	printf("__________________________________________________________________________________\n");
	for(int i=0;i<48;i++)
	{
		/*if((strcmp(bus_obj[i].from,from_input)==0&&strcmp(bus_obj[i].to,dest_input)==0)&&bus_obj[i].time>=time1)
		{	printf("Bus No:%d \tStart_Location:%s \tDestionation_location:%s \tSeats_Available=%d \tArraival_Time:%.2f\n",bus_obj[i].busno,bus_obj[i].from,bus_obj[i].to,bus_obj[i].totalseats,bus_obj[i].time);
		}*/
		if(from<to)
		{
		if((find(48,from_input,i)&&find(48,dest_input,i))&&bus_obj[i].time>=time1&&bus_obj[i].busno<=24)
		{	printf("|  %d \t|  %s \t|    %s \t|\t%d \t  | %.2f\t|\n",bus_obj[i].busno,bus_obj[i].from,bus_obj[i].to,bus_obj[i].totalseats,bus_obj[i].time);
		}
		}
		else
		{
	        if((find(48,from_input,i)&&find(48,dest_input,i))&&bus_obj[i].time>=time1&&bus_obj[i].busno>=25)
		{	printf("|  %d \t|  %s \t|    %s \t|\t%d \t  | %.2f\t|\n",bus_obj[i].busno,bus_obj[i].from,bus_obj[i].to,bus_obj[i].totalseats,bus_obj[i].time);
		}
		}
	}
	printf("__________________________________________________________________________________\n");

}
int no_of_seats(int index,int flag){
	struct bus b1=bus_obj[index];
	if(flag==1){
	for(int i=0;i<ticket_count;i++){
		/*if(strcmp(bus_obj[index].tickets[i].from,a[from-1])==0){
			if(bus_obj[index].seatavb>0)
				{	//printf("MINUS");
				bus_obj[index].seatavb--;
			}
			else{
				return 0;
			}*/
		if(from<to){
			for(int j=1;j<from;j++){
			if(strcmp(bus_obj[index].tickets[i].to,a[j])==0){
				if(bus_obj[index].seatavb<60){
					bus_obj[index].seatavb++;
				}
		}}}
		else{
			for(int j=to;j>from;j--){
			if(strcmp(bus_obj[index].tickets[i].to,a[j])==0){
				if(bus_obj[index].seatavb<60){
					bus_obj[index].seatavb++;
				}
		}}}
	}
}
		else{

for(int i=0;i<ticket_count;i++){
		if(strcmp(b1.tickets[i].to,a[from-1])==0){
			if(b1.seatavb<60){
				b1.seatavb++;
			}
			else
				return b1.totalseats;
		}
	}
		return b1.seatavb;}
	return bus_obj[index].seatavb;
}
//To Book the ticket
void book_ticket(int index)
{	char flag;
	bus_obj[index].seatavb=no_of_seats(index,1);
	printf("\nThe estimated availabe seats for you is  %d\n",bus_obj[index].seatavb);
	
    printf("Do you wanna book(1/0)?\n");
    getchar();
	l:scanf("%c",&flag);
    getchar();
    /*if(flag=='1')
    {
        
    }
    else if(flag=='0')
    {
        
    }*/
    if(flag!='1' && flag!='0')
    {
        printf("Just select from the given option:)\n");
        goto l;
    }
    
    
	if(flag=='1'){
		if(bus_obj[index].seatavb>0){
			//struct ticket t1=bus_obj[index].tickets[bus_obj[index].totalseats-bus_obj[index].seatavb];
			//printf("\nBF:%d\n",b1.seatavb);
			bus_obj[index].seatavb--;
			//ticket_count++;
			//printf("\nBF:%d\n",b1.seatavb);
			strcpy(bus_obj[index].tickets[ticket_count].from,a[from-1]);
			printf("KP:%s",bus_obj[index].tickets[ticket_count].from);
			strcpy(bus_obj[index].tickets[ticket_count].to,a[to-1]);
			bus_obj[index].tickets[ticket_count].price=ticket_price(from,to);
			print_ticket(bus_obj[index].tickets[ticket_count]);
			ticket_count++;
			}
	
	else{
		printf("Unfortunately,The seats are full\n");
		return;
	}
    }
}
void main()
{//creating struct users
 struct user u1,u2,u3,u4;
    struct ticket t1,t2,t3,t4;
    float tk=0.0;
    int bus_id,aks;

    for(int i=0;i<48;i++)
    {
        bus_obj[i].busno=i+1;
        bus_obj[i].totalseats=bus_obj[i].seatavb=60;
	bus_obj[i].time=tk;
	tk=tk+1.0;
	if(i<=24)
	{
	for(int j=0;j<strlen(a[0]);j++)
        bus_obj[i].from[j]=a[0][j];
	for(int j=0;j<strlen(a[9]);j++)
        bus_obj[i].to[j]=a[9][j];
        }
	else
	{
	for(int j=0;j<strlen(a[9]);j++)
        bus_obj[i].from[j]=a[9][j];
	for(int j=0;j<strlen(a[0]);j++)
        bus_obj[i].to[j]=a[0][j];
	}
	if(tk==24.00)
	tk=0.0;
    }
    login();
do{
void_fromto();
float t;
//Enter from location
printf("Enter the time you want to board(24hr):\n");

l:scanf("%f",&t);

if(t<0 || t>23.59)
{
    printf("Just enter the time,not something:)\n");
    goto l;
}
Buses_in_From_To_Destination(a[from-1],a[to-1],t);
//for(int i=0;i<48;i++)
//printf("%s\n",bus_obj[i].to);
printf("Book Tickets(Enter the bus ID)\n");
scanf("%d",&bus_id);
book_ticket(bus_id-1);
printf("Do you wanna Book Tickets Again(1.yes 2.no)\n");
scanf("%d",&aks);
if(aks==2)
break;
}while(1);
}
