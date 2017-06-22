#include <bits/stdc++.h>
#define f float
using namespace std;
 
int sgn(f n)
{
    if(n>0) return 1;
    else if(n==0) return 0;
    else return -1;
}
 
int main()
{
    ofstream myfile;
    myfile.open("network.txt");
    f r1,r2,r3,x=0;
    for(f pi_u1=0; pi_u1<=4; pi_u1+=0.1)
    {
        for(f pi_v1=0; pi_v1<=4; pi_v1+=0.1)
        {
            for(f pi_u2=0; pi_u2<=4; pi_u2+=0.1)
            {
                for(f pi_v2=0; pi_v2<=4; pi_v2+=0.1)
                {
                    for(f pi_u3=0; pi_u3<=4; pi_u3+=0.1)
                    {
                        for(f pi_v3=0; pi_v3<=4; pi_v3+=0.1)
                        {
							r1 = sgn(2-pi_u1)*sqrt(abs(2-pi_u1)) + sgn(2-pi_u2)*sqrt(abs(2-pi_u2)) + sgn(2-pi_u3)*sqrt(abs(2-pi_u3));
							r1 = roundf(r1*1000)/1000;
							r2 = sgn(pi_v1-1)*sqrt(abs(pi_v1-1)) + sgn(pi_v2-1)*sqrt(abs(pi_v2-1)) + sgn(pi_v3-1)*sqrt(abs(pi_v3-1));
							r2 = roundf(r2*1000)/1000;
							if(r1==r2)
							{
								r3 = sgn(pi_u1-pi_v1)*sqrt(abs(pi_u1-pi_v1)) + sgn(pi_u2-pi_v2)*sqrt(abs(pi_u2-pi_v2)) + sgn(pi_u3-pi_v3)*sqrt(abs(pi_u3-pi_v3));
								r3 = roundf(r3*1000)/1000;
								if(r3==r1 && r1>0) 
								{
									//cout<<r1<<endl;
									if(r1>=x) 
									{
										x=r1;
                                        myfile<<"x="<<r1<<" pi_u1="<<pi_u1<<" pi_u2="<<pi_u2<<" pi_u3="<<pi_u3<<" pi_v1="<<pi_v1<<" pi_v2="<<pi_v2<<" pi_v3="<<pi_v3<<"\n";
										cout<<"x="<<r1<<" pi_u1="<<pi_u1<<" pi_u2="<<pi_u2<<" pi_u3="<<pi_u3<<" pi_v1="<<pi_v1<<" pi_v2="<<pi_v2<<" pi_v3="<<pi_v3<<"\n";
									}
								}
							}
							//cout<<pi_u1<<" "<<pi_u2<<" "<<pi_u3<<" "<<pi_v1<<" "<<pi_v2<<" "<<pi_v3<<" "<<endl;
						}
                    }
                }
            }
        }
    }
return 0;
}
