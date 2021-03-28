/*
the gauss elimination process
for
ax1 + by1 + cz1 = d1
ax2 + by2 + cz2 = d2
ax3 + by3 + cz3 = d3

eg 
1x+1y-1z = 9
+8y+6z = -6
-2x+4y-6z = 40
it gives values of x,y,z for uniques solution and gives the upper limit for infinite solution

*/
#include <stdio.h>
#define size 3

static double x, y, z;
enum{
    False,
    True
};


struct linear_sys{
    double a,b,c,d;
};


int check_uppertri(struct linear_sys *xyz){
    if((xyz+0)->a !=0.0 && (xyz+1)->a ==0.0 && (xyz+1)->b !=0.0 && (xyz+2)->a ==0.0 && (xyz+2)->b ==0.0 && (xyz+2)->c !=0.0)
        return True;
    else
        return False;
}


void cal_gauss(struct linear_sys *p){
    double k=0.0,t=0.0;
    int pos = 2;
    while(check_uppertri(p)==False){
        if((p+1)->a == 0.0){
            t = (p+1)->a;
            (p+1)->a = (p+2)->a;
            (p+2)->a = t;

            t = (p+1)->b;
            (p+1)->b = (p+2)->b;
            (p+2)->b = t;

            t = (p+1)->c;
            (p+1)->c = (p+2)->c;
            (p+2)->c = t;

            t = (p+1)->d;
            (p+1)->d = (p+2)->d;
            (p+2)->d = t;
            pos--;
        }
        else if((p+0)->a == 0.0){
            t = (p+0)->a;
            (p+0)->a = (p+2)->a;
            (p+2)->a = t;

            t = (p+0)->b;
            (p+0)->b = (p+2)->b;
            (p+2)->b = t;

            t = (p+0)->c;
            (p+0)->c = (p+2)->c;
            (p+2)->c = t;

            t = (p+0)->d;
            (p+0)->d = (p+2)->d;
            (p+2)->d = t;
            pos--;
        }
        else{
            k= ((p+pos-1)->a)/((p+pos)->a);
            (p+pos)->a = (p+pos-1)->a - k*((p+pos)->a);
            (p+pos)->b = (p+pos-1)->b - k*((p+pos)->b);
            (p+pos)->c = (p+pos-1)->c - k*((p+pos)->c);
            (p+pos)->d = (p+pos-1)->d - k*((p+pos)->d);
            pos--;
            if(pos==0){
                pos=2;
                k= ((p+pos-1)->b)/((p+pos)->b);
                (p+pos)->a = (p+pos-1)->a - k*((p+pos)->a);
                (p+pos)->b = (p+pos-1)->b - k*((p+pos)->b);
                (p+pos)->c = (p+pos-1)->c - k*((p+pos)->c);
                (p+pos)->d = (p+pos-1)->d - k*((p+pos)->d);
                break;
            }
        }
    }
    printf("its a upper triangular matrix\n");
}


int main(){
    struct linear_sys sys[size];
    printf("\nenter the linear system of equation for 3 variable(X,Y,Z)\n");
    int i;
    for(i=0; i<size; i++){
        printf("enter the coefficent for x,y,z & constant in equation %d \n",(i+1));
        scanf("%lf%lf%lf%lf",&(sys+i)->a,&(sys+i)->b,&(sys+i)->c,&(sys+i)->d);
    }


    for(i=0; i<size; i++)
       printf("%0.1lf\t%0.1lf\t%0.1lf\t|\t%0.1lf\n",(sys+i)->a,(sys+i)->b,(sys+i)->c,(sys+i)->d);

    printf("\n\nModifyed matrix:\n");
    cal_gauss(sys);
    for(i=0; i<size; i++)
        printf("%0.4lf\t%0.4lf\t%0.4lf\t|\t%0.4lf\n",(sys+i)->a,(sys+i)->b,(sys+i)->c,(sys+i)->d);

    z=(sys+2)->d / (sys+2)->c;
    y=((sys+1)->d - (sys+1)->c * z) / (sys+1)->b;
    x=(sys->d - sys->c *z - sys->b *y) / (sys->a);
    printf("\nValue of X,Y,Z\n");
    printf("\tX: %0.2lf\t",x);
    printf("\tY: %0.2lf\t",y);
    printf("\tZ: %0.2lf\t",z);
    return 0;
}