#include <stdio.h>
#include <stdlib.h>

void conv_to_words(int *num){
//millions
char *single_digits_million[] = {"jeden million", "dwa milliony", "trzy millony",
                            "cztery milliony", "pięć millionów",
                               "sześć milionów", "siedem milionów",
                               "osiem milionów", "dziewięć milionów"};
//thousands
char *single_digits_thousand[] = {"tysiąc", "dwa tysiące", "trzy tysiące",
                            "cztery tysiące", "pięć tysięcy",
                               "sześć tysięcy", "siedem tysięcy",
                               "osiem tysięcy", "dziewięć tysięcy"};

//single
char *single_digits[] = {"jeden", "dwa", "trzy",
                            "cztery", "pięć",
                               "sześć", "siedem",
                               "osiem", "dziewięć"};

char *two_digits[] = {"", "jedenaście", "dwanaście",
                               "trzynaście", "czternaście",
                               "piętnaście", "szesnaście",
                               "siedemnaście", "osiemnaście", "dziewiętnaście"};

char *tens_multiple[] = {"", "dziesięć", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdzieśiąt",
                            "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt"};

char *tens_power[] = {"sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset",
                          "siedemset", "osiemset", "dziewięćset", "tysiąc"};

//code
   int b = num;
   printf("%d\n", b);

   int million = b%1000000000/1000000;
   int thouthand = b%1000000/1000;
   int hundred = b%1000;

   int len_million = floor(log10(abs(million))) + 1;
   int len_thouthand = floor(log10(abs(thouthand))) + 1;
   int len_hundred = floor(log10(abs(hundred))) + 1;


   if (million == 0 && thouthand == 0 && hundred == 0){
    printf("zero\n");
    return 0;
   }

   //millions
    if (million != 0){
        if (len_million == 3){
        int d_m = million/100;
        if (million%100 == 00){
        printf("%s milionów ", tens_power[d_m - 1]);
        } else if (million%100/10 == 0) {
            printf("%s ", tens_power[d_m - 1]);
            printf("%s ", single_digits_million[million%10 - 1]);
        } else if (million%100 >= 11 && million%100 <= 19){
            printf("%s ", tens_power[d_m - 1]);
            printf("%s milionów ", two_digits[million%10 ]);
        } else if (million%10 == 0){
            printf("%s ", tens_power[d_m - 1]);
        printf("%s milionów ", tens_multiple[million%100/10 ]);
        } else {
            printf("%s ", tens_power[d_m - 1]);
        printf("%s ", tens_multiple[million%100/10 ]);
            printf("%s ", single_digits_million[million%10 - 1 ]);
        }

        }else if (len_million == 2){
           if (million%10 == 0){
             printf("%s milionów ", tens_multiple[million%100/10 ]);
            } else if (million%100 >= 11 && million%100 <= 19){
                printf("%s milionów ", two_digits[million%10 ]);
            } else {
            printf("%s ", tens_multiple[million%100/10 ]);
            printf("%s ", single_digits_million[million%10 - 1 ]);
            }

        }else if (len_million == 1){
            if (thouthand != 0){
           printf("%s ", single_digits_million[million - 1]);
           } else {
             printf("%s \n", single_digits_million[million - 1]);
           }
    
        }

    }
    //thouthand
   if (thouthand != 0){
   if (len_thouthand == 3){
        int d_m = thouthand/100;
        if (thouthand%100 == 00){
        printf("%s tysięcy ", tens_power[d_m - 1]);
        } else if (thouthand/10 == 00){                    
            printf("%s ", single_digits_thousand[thouthand%10 - 1 ]);
        } else if (thouthand%100/10 == 0) {
            printf("%s ", tens_power[d_m - 1]);
            printf("%s ", single_digits_thousand[thouthand%10 - 1]);
        } else if (thouthand%100 >= 11 && thouthand%100 <= 19){
            printf("%s ", tens_power[d_m - 1]);
            printf("%s tysięcy ", two_digits[thouthand%10 ]);
        } else if (thouthand%10 == 0){
            printf("%s ", tens_power[d_m - 1]);
        printf("%s tysięcy ", tens_multiple[thouthand%100/10 ]);
        } else {
            printf("%s ", tens_power[d_m - 1]);
        printf("%s ", tens_multiple[thouthand%100/10 ]);
            printf("%s ", single_digits_thousand[thouthand%10 - 1 ]);
        }

        }else if (len_thouthand == 2){
           if (thouthand%10 == 0){
             printf("%s tysięcy ", tens_multiple[thouthand%100/10 ]);
            } else if (thouthand%100 >= 11 && thouthand%100 <= 19){
                printf("%s tysięcy ", two_digits[thouthand%10 ]);
            } else {
            printf("%s ", tens_multiple[thouthand%100/10 ]);
            printf("%s ", single_digits_thousand[thouthand%10 - 1 ]);
            }

        }else if (len_thouthand == 1){
            if (hundred != 0){
           printf("%s ", single_digits_thousand[thouthand - 1]);  
            } else {
            printf("%s \n", single_digits_thousand[thouthand - 1]);
            }
        }



    }

    //hundred
   if (hundred != 0){
 if (len_hundred == 3){
        int d_m = hundred/100;
        if (hundred%100 == 00){
        printf("%s ", tens_power[d_m - 1]);
        } else if (thouthand/10 == 00){                     
            printf("%s ", single_digits_thousand[thouthand%10 - 1 ]);
        } else if (hundred%100/10 == 0) {
            printf("%s ", tens_power[d_m - 1]);
            printf("%s ", single_digits[hundred%10 - 1]);
        } else if (hundred%100 >= 11 && hundred%100 <= 19){
            printf("%s ", tens_power[d_m - 1]);
            printf("%s ", two_digits[hundred%10 ]);
        } else if (hundred%10 == 0){
            printf("%s ", tens_power[d_m - 1]);
        printf("%s \n", tens_multiple[hundred%100/10 ]);

        } else {
            printf("%s ", tens_power[d_m - 1]);
        printf("%s ", tens_multiple[hundred%100/10 ]);
            printf("%s \n", single_digits[hundred%10 - 1 ]); //the last \n
        }
		
        }else if (len_hundred == 2){

           if (hundred%10 == 0){
             printf("%s \n", tens_multiple[hundred%100/10 ]);
            } else if (hundred%100 >= 11 && hundred%100 <= 19){
                printf("%s\n", two_digits[hundred%10 ]);

            } else {
            printf("%s ", tens_multiple[hundred%100/10 ]);
            printf("%s \n", single_digits[hundred%10 - 1 ]);

            }

        }else if (len_hundred == 1){
           printf("%s\n", single_digits[hundred - 1]);
        return;
        }



    }


}

int main(int argc, char* argv[])
{
system("chcp 65001  > nul");

for (int i = 1; i < argc; i++ ){
    conv_to_words(atoi(argv[i]));
}
    return 0;
}



