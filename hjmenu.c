/**************************************************************************************************/
/* Copyright (C) HaoJie, 2014-2015                                                                */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  HaoJie                                                               */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/14                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10


/*define struct*/
typedef struct DataNode
{
    char*    cmd;
    char*    desc;
	int 	 (*handler)();
    struct  DataNode *next;
} tDataNode;


tDataNode* FindCmd(tDataNode *head,char *cmd)
{
		if(head == NULL || cmd == NULL)
		{
			return NULL;
		}
		tDataNode *p =head;
		while (p!= NULL)
		{
			if(!strcmp(p->cmd,cmd))
			{
				return p;
				break;
			}
			p=p->next;
		}
		
		return NULL;
}

/* show cmd*/

int ShowAllCmd(tDataNode *head)
{
	printf("Menu List:\n");
	tDataNode *p=head;
	while(p!= NULL)
	{
		printf("%s -%s\n",p->cmd,p->desc);
		p=p->next;
	}
	return 0;
}
static tDataNode head[] =
{
	{"help","this is help cmd!",Help,&head[1]},
	{"version","menu program v1.0",NULL,NULL}
};

/* cmd line begins*/
main()
{	
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd number >");
		scanf("%s",cmd);
		tDataNode *p=FindCmd(head, cmd);
		if(p== NULL)
		{
			printf("This is a wrong cmd!\n");
			continue;
		}
		printf("%s - %s\n",p->cmd,p->desc);
		if(p->handler != NULL)
		{
			p->handler();
		}
		
	}
	
	
}

/* show all cmds for help*/
int Help()
{
	ShowAllCmd(head);
	return 0;
}
