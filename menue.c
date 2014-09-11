/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  zoujia_menu.c                                                        */
/*  PRINCIPAL AUTHOR      :  Zoujia                                                               */
/*  SUBSYSTEM NAME        :  zoujia_menu                                                          */
/*  MODULE NAME           :  zoujia_menu                                                          */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/10                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{
    char    cmd[DESC_LEN];
    char    desc[DESC_LEN];
    struct  DataNode *next;
} tDataNode;

/*check the cmd repeat or not*/
int Check(char* cmd,tDataNode *head)
{
	 tDataNode * p = NULL;
	 p = head;
	while(p != NULL)
	{
		if(strcmp(cmd,p->cmd) == 0)
		{
			printf("repeat!please reinput\n");
			return 1;
		}
		p = p->next;
	}
	return 0;
}

 /* Init cmd list */
tDataNode* Init(tDataNode *head)
{
	int i;
	tDataNode * p = NULL;
	 for (i=0; i<CMD_NUM; i++)
    {
        p = (tDataNode*)malloc(sizeof(tDataNode));
       
        printf("please input %d cmd\n",i);
		scanf("%s",p->cmd);
		while( Check(p->cmd,head) == 1)
		{
			printf("please reinput %d cmd\n",i);
			scanf("%s",p->cmd);
		}
       
        snprintf(p->desc, DESC_LEN, "This is %s cmd!", p->cmd);
        p->next = head;
        head = p;
    }
	 return head;
}

/*show cmd list*/
void ShowList(tDataNode *p)
{
	 while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
}

/* cmd line begins */
void LineBegins(tDataNode *head)
{
	tDataNode *p;
	while(1)
    {
        char cmd[DESC_LEN];
        printf("Input a cmd > ");
		scanf("%s",cmd);
  
        p = head;
        while(p != NULL)
        {
            if(strcmp(cmd,p->cmd) != 0)
            {
                p = p->next;
                continue;
            }
            else
            {
                break;
            }
        }
        
        if(!p)
        {
            printf("This is a wrong cmd !\n ");
            continue;
        }
        
        p = head;
        while(p != NULL)
        {
            if(strcmp(cmd,p->cmd) == 0)
            {
                printf("%s - %s\n", p->cmd, p->desc);
                break;
            }
            p = p->next;
        }
    }
}

main()
{
    tDataNode *head = NULL;
    tDataNode * p = NULL;
	  head = Init(head);  /* Init cmd list */
    printf("Menu List:\n");
    p = head;
	  ShowList(p);        /*show cmd list*/              
	  LineBegins(head);   /* cmd line begins */
}
