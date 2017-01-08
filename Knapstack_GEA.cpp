#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

/*============= һЩ��Ҫ�ĳ��� ===============*/
#define POP_SIZE 200            // ��Ⱥ�Ĺ�ģ
#define PRO_CROSS 0.618            // �������
#define PRO_MUTATE 0.03            // �������
#define CHROM_SIZE 500           // Ⱦɫ�峤��
#define GENERATION_NUM 30        // ��ֳ����
/*============================================*/

// ������
struct population{
    unsigned int chrom[CHROM_SIZE];        // ������
    double weight;                        // ��������
    double fitness;                        // ��Ӧ��
    unsigned int parent1,parent2,cross;    // ˫�ף�����ڵ�
};

// ����������һ������Ⱥ
struct population oldPop[POP_SIZE], newPop[POP_SIZE];

// ��������������棬����������
int weight[CHROM_SIZE], profit[CHROM_SIZE], contain;

// ��Ⱥ���ܵ���Ӧ�ȣ���С�����ƽ����Ӧ�ȡ�
double sumFitness, minFitness, maxFitness, avgFitness;

// ������Ӧ��ʱ���õĳͷ�����ϵ��
double alpha;

// һ����Ⱥ��������С��Ӧ�ȸ���
int minPop, maxPop;


double calWeight( unsigned int *chr ){
    double popSumWeight = 0;
    for(int i = 0; i < CHROM_SIZE; i++){
        popSumWeight += (*chr) * weight[i];
        chr++;
    }
    return popSumWeight;
}


double calFit( unsigned int *chr ){
    double popProfit = 0;
    for(int i = 0; i < CHROM_SIZE; i++){
        popProfit += (*chr) * profit[i];
        chr++;
    }
    return popProfit;
}


void statistics( struct population *pop ){
    double tmpFitness;

    sumFitness = pop[0].fitness;
    minFitness = pop[0].fitness;
    minPop = 0;
    maxFitness = pop[0].fitness;
    maxPop = 0;

    for( int i =1; i < POP_SIZE; i++ ){
    // ������Ⱥ������Ӧ��
        sumFitness += pop[i].fitness;
        tmpFitness = pop[i].fitness;
        // ѡ�������Ӧ�ȵĸ����λ�ú���Ӧ�ȵ�ֵ
        if( (tmpFitness > maxFitness) && ((int)(tmpFitness*10)%10 == 0) ){
            maxFitness = pop[i].fitness;
            maxPop = i;
        }
        // ѡ����С��Ӧ�ȵĸ����λ��
        if( (tmpFitness < minFitness) ){
            minFitness = pop[i].fitness;
            minPop = i;
        }
    avgFitness = sumFitness / (float)POP_SIZE;
    }
}

void report( struct population *pop, int gen ){
    int popWeight = 0;
    printf("\nThe generation is %d.\n", gen);        // �����Ⱥ�Ĵ���
    // �����Ⱥ�������Ӧ�ȸ����Ⱦɫ����Ϣ
    printf("The population chrom is: \n");
    for( int j = 0; j < CHROM_SIZE; j++ ){
        if( j % 5 == 0 ) {printf(" ");}
        // ÿ������λ���
        printf("%1d", pop[maxPop].chrom[j]);
    }
    printf("\n�Ŵ��㷨����������ܼ�ֵΪ: %d.", (int)pop[maxPop].fitness);
    printf("\n���뱳����������Ϊ: %d.\n", (int)pop[maxPop].weight);
}


void initPop(){
    int i, j;
    double tmpWeight;
    bool isPop = false;
    // ����һ��������Ⱥ
    for( i = 0; i < POP_SIZE; i++ ){
        while(!isPop){
            // ���������������������������ֱ������ͬ�ĸ���
            for( j = 0; j < CHROM_SIZE; j++ ){
                oldPop[i].chrom[j] = rand()%2;    // ����0/1������һ����
                oldPop[i].parent1 = 0;
                oldPop[i].parent2 = 0;
                oldPop[i].cross = 0;
            }
            // ѡ������С�ڱ��������ĸ��壬���������ĸ���

            tmpWeight = calWeight( oldPop[i].chrom );
            if( tmpWeight <= contain ){
                oldPop[i].fitness = calFit( oldPop[i].chrom );
                oldPop[i].weight = tmpWeight;
                oldPop[i].parent1 = 0;
                oldPop[i].parent2 = 0;
                oldPop[i].cross = 0;
                isPop = true;
            }
        }
        isPop = false;
    }
}

int excise( double probability ){
    double pp;
    pp = (double)(rand()%20001/20000.0);
    if( pp <= probability )
        return 1;
    return 0;
}


int    selection(int pop){
    double wheelPos, randNumber,partsum = 0;
    int i = 0;
    // �ֶķ�
    randNumber=(rand()%2001)/2000.0;
    wheelPos = randNumber*sumFitness;
    do {
        partsum += oldPop[i].fitness;
        i++;
    }while( ( partsum < wheelPos) && (i < POP_SIZE) );
    return i-1;
}


int crossOver(unsigned int *parent1, unsigned int *parent2, int i){
    int j;                    // ������Ļ���λ��
    int crossPos;            // �����λ��
    if( excise(PRO_CROSS) ){
        crossPos = rand()%(CHROM_SIZE-1);
    }else{
        crossPos = CHROM_SIZE - 1;
    }
    // ��ʼ����
    for( j = 0; j <= crossPos; j++ ){
        newPop[i].chrom[j] = parent1[j];
    }
    for( j = crossPos+1; j < CHROM_SIZE; j++ ){
        newPop[i].chrom[j] = parent2[j];
    }
    newPop[i].cross = crossPos;
    return 1;
}


int mutation(unsigned int alleles){
    if( excise(PRO_MUTATE) ){
        // ����ͻ����ʣ���˻���ͻ��
        alleles == 0? alleles = 1: alleles = 0;
    }
    return alleles;
}


void generation(){
    unsigned int i, j, mate1, mate2;
    double tmpWeight = 0;
    bool notGen;
    for( i = 0; i < POP_SIZE; i++){
        notGen = false;
        // ��Ҫ��ֳ
        while( !notGen ){
            // ѡ��ѡ���м��ʲ�����������ĸ�ĸ����λ��
            mate1 = selection(i);
            mate2 = selection(i+1);
            // ���棺������һ���滻������������������i
            crossOver( oldPop[mate1].chrom, oldPop[mate2].chrom, i);
            for( j = 0; j < CHROM_SIZE; j++ ){
                // ���죺�¸���һ��һ������λ�ô��룬���Ƿ�Ҫͻ��
                newPop[i].chrom[j] = mutation(newPop[i].chrom[j]);
            }
            // ѡ������С�ڱ��������ĸ��壬��������,��Ѽ�ֵ����¼����
            tmpWeight = calWeight( newPop[i].chrom );
            if( tmpWeight <= contain ){
                newPop[i].fitness = calFit( newPop[i].chrom );
                newPop[i].weight = tmpWeight;
                newPop[i].parent1 = mate1;
                newPop[i].parent2 = mate2;
                notGen = true;                // ����Ҫ�ٲ����Ӵ�
            }
        }
    }
}

int main(int argc, char* argv[]){
    int gen, oldMaxPop, k,sumw=0;
    double oldMax;
    printf("\n�����������Ʒ�ļ�ֵ:\n");
    for(int j = 0; j < CHROM_SIZE; j++ )
    {
        profit[j]=1+rand()%101;
        printf("%d\n",profit[j]);
        //cout<<"���������Ʒ��ֵ��"<<profit[j]<<endl;
    }
    printf("\n�����������Ʒ������:\n");
    for(int i = 0; i < CHROM_SIZE; i++ )
    {
        weight[i]=1+rand()%101;
        printf("%d\n",weight[i]);
        //cout<<"���������Ʒ������"<<weight[i]<<endl;
        sumw+=weight[i];
    }
    contain = sumw/2;
    printf("����������Ϊ��%d\n",contain);
    //cout<<"����������Ϊ��"<<contain<<endl;
    gen = 0;                        // �����һ������Ҫ���������ʾ�ϣ�

    srand( (unsigned)time(NULL) );    // ���������
    initPop();                        // ��ʼ����Ⱥ
    memcpy(&newPop,&oldPop,POP_SIZE*sizeof(struct population));
    statistics( newPop );            // ��������Ⱥ����Ϣ����Ӧ�ȵȣ�
    report( newPop, gen );
    while( gen < GENERATION_NUM ){
        gen += 1;
        if( gen % 100 == 0 )
            srand( (unsigned)time(NULL) );    // ÿһ�ٴ������µ������
        oldMax = maxFitness;        // �������Ӧ�ȸ���һ��
        oldMaxPop = maxPop;            // ӵ�������Ӧ�ȵĸ���λ�ø���һ��
        generation();
        statistics( newPop );

        // ����µ������Ӧ��С����һ�������Ӧ�ȣ�����һ������
        if( maxFitness < oldMax ){
            for( k = 0; k < CHROM_SIZE; k++ ){
                newPop[minPop].chrom[k] = oldPop[oldMaxPop].chrom[k];
            }
            newPop[minPop].fitness = oldPop[oldMaxPop].fitness;
            newPop[minPop].parent1 = oldPop[oldMaxPop].parent1;
            newPop[minPop].parent2 = oldPop[oldMaxPop].parent2;
            newPop[minPop].cross = newPop[minPop].cross;
            statistics(newPop);
        }else if( maxFitness > oldMax ){
            report(newPop, gen);
        }
         //������������Ⱥ����Ϣ����һ����Ⱥ��Ϣ�ռ�
        memcpy(&oldPop,&newPop,POP_SIZE*sizeof(struct population));
    }
    return 0;
}
