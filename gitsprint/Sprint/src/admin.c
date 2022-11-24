#include<common.h>

void editAlumniInfo()
{
	FILE *fp;
	SIGNUP *sn = (SIGNUP *)malloc(sizeof(SIGNUP));
	int a, f = 0;
	printf("\n\t\tEnter the Registration number to be searched : ");
	scanf("%d",&a);
	fp = fopen("Users.txt","r+");
	if(fp == NULL)
	{
		printf("Unable to open the file");
		exit(0);
	} else {
		while(fread(sn,sizeof(SIGNUP),1,fp))
		{
			if(a==sn->uni_id)
			{
				f = 1;
				break;
			}
		}
		if(f==1){
			editInfo(sn->uni_id);
		}
	}			
	fclose(fp);
	free(sn);
}


int deleteAlumniInfo(){
    int flag=0;
    int uni_no;
    FILE *fp;
    FILE *p2;
    SIGNUP *sn = (SIGNUP *)malloc(sizeof(SIGNUP));
    printf("\n\n\t\tEnter the University no : ");
    scanf("%d",&uni_no);
    fp=fopen("Users.txt","r");
    p2=fopen("temp.txt","a+");
    if(fp == NULL)
	{
		printf("Unable to open the file");
		return 0;
	}
    while(fread(sn,sizeof(SIGNUP),1,fp))
    {
        if(uni_no!=sn->uni_id){
            fwrite(sn,sizeof(SIGNUP),1,p2);
        } else {
            flag = 1;
        }
    }
    fclose(fp);
    fclose(p2);
    remove("Users.txt");
    rename("temp.txt","Users.txt");
    if(flag==0)
    {
        printf("\n\n\t\tInvalid university no.!!");
    }
    else
    {
        printf("\n\n\t\tRecord Deleted!!");
    }
    free(sn);
    return 0;
}
int reportNonPlacStu(char placed[])
{
	FILE *fp;
	int i=0;
	char option[10];
	printf("\nEnter status of placement: ");
	scanf("%s",option);

	STUDS *ss=(STUDS *)malloc(sizeof(STUDS));
	fp=fopen("stuUsers.txt","r");
	if(fp==NULL)
	{
		printf("Unable to open the file");
		exit(0);
	}
	else
	{
		while(fread(ss,sizeof(STUDS),1,fp))
		{
			if(strcmp(placed ,option)==1)
			{
				i++;
			}
		}
	}
	fclose(fp);
	free(ss);
	return i;
}


