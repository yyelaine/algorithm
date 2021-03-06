#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

/*============= 一些必要的常量 ===============*/
#define POP_SIZE 200            // 种群的规模
#define PRO_CROSS 0.618            // 交叉概率
#define PRO_MUTATE 0.03            // 变异概率
#define CHROM_SIZE 500           // 染色体长度
#define GENERATION_NUM 30        // 繁殖代数
/*============================================*/

// 个体类
struct population{
    unsigned int chrom[CHROM_SIZE];        // 基因组
    double weight;                        // 背包重量
    double fitness;                        // 适应度
    unsigned int parent1,parent2,cross;    // 双亲，交叉节点
};

// 新生代和上一代的种群
struct population oldPop[POP_SIZE], newPop[POP_SIZE];

// 物体的重量，收益，背包的容量
int weight[CHROM_SIZE], profit[CHROM_SIZE], contain;

// 种群的总的适应度，最小，最大，平均适应度。
double sumFitness, minFitness, maxFitness, avgFitness;

// 计算适应度时，用的惩罚函数系数
double alpha;

// 一个种群的最大和最小适应度个体
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
    // 计算种群的总适应度
        sumFitness += pop[i].fitness;
        tmpFitness = pop[i].fitness;
        // 选择最大适应度的个体的位置和适应度的值
        if( (tmpFitness > maxFitness) && ((int)(tmpFitness*10)%10 == 0) ){
            maxFitness = pop[i].fitness;
            maxPop = i;
        }
        // 选择最小适应度的个体的位置
        if( (tmpFitness < minFitness) ){
            minFitness = pop[i].fitness;
            minPop = i;
        }
    avgFitness = sumFitness / (float)POP_SIZE;
    }
}

void report( struct population *pop, int gen ){
    int popWeight = 0;
    printf("\nThe generation is %d.\n", gen);        // 输出种群的代数
    // 输出种群中最大适应度个体的染色体信息
    printf("The population chrom is: \n");
    for( int j = 0; j < CHROM_SIZE; j++ ){
        if( j % 5 == 0 ) {printf(" ");}
        // 每个基因单位输出
        printf("%1d", pop[maxPop].chrom[j]);
    }
    printf("\n遗传算法产生的最大总价值为: %d.", (int)pop[maxPop].fitness);
    printf("\n放入背包的总重量为: %d.\n", (int)pop[maxPop].weight);
}


void initPop(){
    int i, j;
    double tmpWeight;
    bool isPop = false;
    // 生成一个祖宗种群
    for( i = 0; i < POP_SIZE; i++ ){
        while(!isPop){
            // 如果不满足条件，则继续随机产生直到有相同的个体
            for( j = 0; j < CHROM_SIZE; j++ ){
                oldPop[i].chrom[j] = rand()%2;    // 产生0/1的任意一个数
                oldPop[i].parent1 = 0;
                oldPop[i].parent2 = 0;
                oldPop[i].cross = 0;
            }
            // 选择重量小于背包容量的个体，满足条件的个体

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
    // 轮赌法
    randNumber=(rand()%2001)/2000.0;
    wheelPos = randNumber*sumFitness;
    do {
        partsum += oldPop[i].fitness;
        i++;
    }while( ( partsum < wheelPos) && (i < POP_SIZE) );
    return i-1;
}


int crossOver(unsigned int *parent1, unsigned int *parent2, int i){
    int j;                    // 基因组的基因位置
    int crossPos;            // 交叉点位置
    if( excise(PRO_CROSS) ){
        crossPos = rand()%(CHROM_SIZE-1);
    }else{
        crossPos = CHROM_SIZE - 1;
    }
    // 开始交叉
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
        // 满足突变概率，则此基因突变
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
        // 需要繁殖
        while( !notGen ){
            // 选择：选择有几率产生优良后代的父母个体位置
            mate1 = selection(i);
            mate2 = selection(i+1);
            // 交叉：产生新一代替换掉不符合生存条件的i
            crossOver( oldPop[mate1].chrom, oldPop[mate2].chrom, i);
            for( j = 0; j < CHROM_SIZE; j++ ){
                // 变异：新个体一个一个基因位置代入，看是否要突变
                newPop[i].chrom[j] = mutation(newPop[i].chrom[j]);
            }
            // 选择重量小于背包重量的个体，满足条件,则把价值给记录起来
            tmpWeight = calWeight( newPop[i].chrom );
            if( tmpWeight <= contain ){
                newPop[i].fitness = calFit( newPop[i].chrom );
                newPop[i].weight = tmpWeight;
                newPop[i].parent1 = mate1;
                newPop[i].parent2 = mate2;
                notGen = true;                // 不需要再产生子代
            }
        }
    }
}

int main(int argc, char* argv[]){
    int gen, oldMaxPop, k,sumw=0;
    double oldMax;
    printf("\n随机产生的物品的价值:\n");
    for(int j = 0; j < CHROM_SIZE; j++ )
    {
        profit[j]=1+rand()%101;
        printf("%d\n",profit[j]);
        //cout<<"随机产生物品价值："<<profit[j]<<endl;
    }
    printf("\n随机产生的物品的重量:\n");
    for(int i = 0; i < CHROM_SIZE; i++ )
    {
        weight[i]=1+rand()%101;
        printf("%d\n",weight[i]);
        //cout<<"随机产生物品重量："<<weight[i]<<endl;
        sumw+=weight[i];
    }
    contain = sumw/2;
    printf("背包总容量为：%d\n",contain);
    //cout<<"背包总重量为："<<contain<<endl;
    gen = 0;                        // 代表第一代（主要用在输出显示上）

    srand( (unsigned)time(NULL) );    // 置随机种子
    initPop();                        // 初始化种群
    memcpy(&newPop,&oldPop,POP_SIZE*sizeof(struct population));
    statistics( newPop );            // 产生新种群的信息（适应度等）
    report( newPop, gen );
    while( gen < GENERATION_NUM ){
        gen += 1;
        if( gen % 100 == 0 )
            srand( (unsigned)time(NULL) );    // 每一百代产生新的随机数
        oldMax = maxFitness;        // 将最大适应度给上一代
        oldMaxPop = maxPop;            // 拥有最大适应度的个体位置给上一代
        generation();
        statistics( newPop );

        // 如果新的最大适应度小于上一代最大适应度，则上一代活着
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
         //保存新生代种群的信息到老一代种群信息空间
        memcpy(&oldPop,&newPop,POP_SIZE*sizeof(struct population));
    }
    return 0;
}
