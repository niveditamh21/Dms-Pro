#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
		int info;
			struct node *llink;
				struct node *mlink;
					struct node *rlink;
};
typedef struct node *NODE;
NODE createtree(NODE R)
{
		int i;
			char dir[20];
				NODE NN,PD,PN;
					NN=(NODE)malloc(sizeof(struct node));
						printf("Enter new value\n");
							scanf("%d",&NN->info);
								NN->rlink=NN->llink=NN->mlink=NULL;
									if(R==NULL) return NN;
										printf("Enter direction\n");
											scanf("%s",dir);
												PN=R;
													PD=NULL;
														for(i=0;i<strlen(dir);i++)
																{
																			PD=PN;
																					if(PN==NULL) break;
																							if(dir[i]=='L') PN=PN->llink;
																									else if(dir[i]=='M') PN=PN->mlink;
																											else PN=PN->rlink;
																												}
															if(PN!=NULL || i!=strlen(dir))
																	{
																				printf("Insertion to this direction not possible\n");
																						free(NN);
																								return R;
																									}
																if(dir[i-1]=='L') PD->llink=NN;
																	else if(dir[i-1]=='R') PD->rlink=NN;
																		else PD->mlink=NN;
																			return R;
}
int Max(int a, int b)
{
		if(a>b)return a;
			else return b;
}
int height(NODE R)
{
		if(R==NULL) return -1;
			return 1+Max(height(R->llink),height(R->rlink));
}
void display1(NODE R)
{
		int i,h;
			NODE TN=R,PD;
				h=height(R);
					if(h==-1)
							{
										printf("Empty\n");
												return;
													}
						if(h==0)
								{
											printf("%d\t",R->info);
													return;
														}
							if(h==1)
									printf("Cross Product not possible!!!\nCross Product is valid among atleast two sets....\nPlease Enter two sets atleast\n");
								if(h==2)
										{
														printf("The cross product of the given sets is\n");
																	PD=TN;
																				if(TN->llink!=NULL)
																								{
																													printf("(%d,%d)\n",TN->llink->info,TN->llink->llink->info);
																																	if(TN->llink->mlink!=NULL)
																																						printf("(%d,%d)\n",TN->llink->info,TN->llink->mlink->info);
																																					printf("(%d,%d)\n",TN->llink->info,TN->llink->rlink->info);
																																								}
																							if(TN->mlink!=NULL)
																											{
																																printf("(%d,%d)\n",TN->mlink->info,TN->mlink->llink->info);
																																				if(TN->mlink->mlink!=NULL)
																																									printf("(%d,%d)\n",TN->mlink->info,TN->mlink->mlink->info);
																																								printf("(%d,%d)\n",TN->mlink->info,TN->mlink->rlink->info);
																																											}
																										if(TN->rlink!=NULL)
																														{
																																			printf("(%d,%d)\n",TN->rlink->info,TN->rlink->llink->info);
																																							if(TN->rlink->mlink!=NULL)
																																												printf("(%d,%d)\n",TN->rlink->info,TN->rlink->mlink->info);
																																											printf("(%d,%d)\n",TN->rlink->info,TN->rlink->rlink->info);
																																													        }	
																											}
									if(h==3)
											{
														printf("The cross product of the given sets is\n");
																PD=TN;
																		if(TN->llink!=NULL)
																						{
																											printf("(%d,%d,%d)\n",TN->llink->info,TN->llink->llink->info,TN->llink->llink->llink->info);
																															printf("(%d,%d,%d)\n",TN->llink->info,TN->llink->llink->info,TN->llink->llink->rlink->info);
																																			printf("(%d,%d,%d)\n",TN->llink->info,TN->llink->rlink->info,TN->llink->rlink->llink->info);
																																							printf("(%d,%d,%d)\n",TN->llink->info,TN->llink->llink->info,TN->llink->llink->rlink->info);
																																										}
																				if(TN->mlink!=NULL)
																								{
																													printf("(%d,%d,%d)\n",TN->mlink->info,TN->mlink->llink->info,TN->mlink->llink->llink->info);
																																	printf("(%d,%d,%d)\n",TN->mlink->info,TN->mlink->llink->info,TN->mlink->llink->rlink->info);
																																					printf("(%d,%d,%d)\n",TN->mlink->info,TN->mlink->rlink->info,TN->mlink->rlink->llink->info);
																																									printf("(%d,%d,%d)\n",TN->mlink->info,TN->mlink->llink->info,TN->mlink->llink->rlink->info);
																																												}
																						if(TN->rlink!=NULL)
																										{
																															printf("(%d,%d,%d)\n",TN->rlink->info,TN->rlink->llink->info,TN->rlink->llink->llink->info);
																																			printf("(%d,%d,%d)\n",TN->rlink->info,TN->rlink->llink->info,TN->rlink->llink->rlink->info);
																																							printf("(%d,%d,%d)\n",TN->rlink->info,TN->rlink->rlink->info,TN->rlink->rlink->llink->info);
																																											printf("(%d,%d,%d)\n",TN->rlink->info,TN->rlink->llink->info,TN->rlink->llink->rlink->info);
																																														}
																							}
}
void main()
{
		int ch;
			NODE R;
				R=NULL;
					for(;;)
							{
										printf("Enter choice:\n1)AXB\n2)BXC\n3)AXC\n4)AXBXC\n5)BXA\n6)Display\n");
												scanf("%d",&ch);
														switch(ch)
																	{
																					case 1:R=createtree(R);break;
																					       			case 2:
																					       			case 3:
																					       			case 4:R=createtree(R);break;
																								case 5:R= createtree(R);break;
																								       			case 6:display1(R);break;
																											       			default:exit(0);
																																	}
															}
}


