#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Burada girdi olarak tanimladigimiz kelimeleri ayirt edip anahtar
// kelime oldu?unu yazacak. Bu kelimelerin türkçelerini biz yazdik.
bool anahtarKelimeMi(char* str)
{
    if (!strcmp(str, "eger") || !strcmp(str, "degilse")
        || !strcmp(str, "iken") || !strcmp(str, "yap")
        || !strcmp(str, "kir") ||!strcmp(str, "devam")
        || !strcmp(str, "katli") || !strcmp(str, "noktali")
        || !strcmp(str, "karak")|| !strcmp(str, "aralik")
        || !strcmp(str, "durum") || !strcmp(str, "karak")
        || !strcmp(str, "boyutu") || !strcmp(str, "uzun")
        || !strcmp(str, "kisa") || !strcmp(str, "tiptani")
        || !strcmp(str, "sec") || !strcmp(str, "durum")
        || !strcmp(str, "bos") || !strcmp(str, "statik")
        || !strcmp(str, "yapi") || !strcmp(str, "git") || !strcmp(str, "tam")
        || !strcmp(str, "varsayilan") || !strcmp(str, "mantiksal")|| !strcmp(str, "basla")
        ){
        return (true);
    }
    else{
        return (false);
    }
}

// Sonlandirici bu karakterleri algiladigi zaman o numarayi operatörü
// ya da stringi sonladirip yeni bir karakter dizisi olu?turmaya devam edecektir.
bool sonlandiriciVarMi(char ch)
{
    if(ch=='<'||ch=='='||ch=='('||ch==')'||ch=='['||ch==' '||ch=='+'||ch==';'||ch=='>'||
       ch=='-'||ch=='*'||ch=='/'||ch==','||ch==']'||ch=='{'||ch=='}'||ch=='=='||ch==':'||ch=='\n'){
            return (true);
        }
    else{
         return (false);
    }
}


bool mantiksalMi(char* str){
	
	if (!strcmp(str, "degil") ) {// mantiksal degil konrtolü
		
		return (true);
	}
	else
		return (false);
	
	
}


bool operatorMu(char* str)
{
    if (!strcmp(str, "ekle") || !strcmp(str, "esitle")|| !strcmp(str, "carp")
	|| !strcmp(str, "cikar")|| !strcmp(str, "yaz")){
    	
    	return (true);
    	
	}
	else 
	    return (false);

}

    

// Eger bir operator gordugu zaman true degeri gondericektir
bool operatorVarMi(char* ch)
{
    if(ch=='<='||ch=='!='||ch=='+'||
        ch=='-'||ch=='*'||
        ch=='/'||ch=='>'||ch=='<'||
        ch=='='||ch=='=='||ch=='>='||ch=='é'||ch=='&'){
            return (true);
        }
    else{
        return (false);
    }
}

// Burada sayi ve karakter(856ab) yada karakter ve operator(ka+) ikilisi yan yana oldugu surece
// hata vericektir.
bool gecerliMi(char* str)
{
    if (sonlandiriciVarMi(str[0])==true||str[0]=='0'||str[0]=='1'||str[0]=='2'||
        str[0]=='3'||str[0]=='4'||str[0]=='5'||
        str[0]=='6'||str[0]=='7'||str[0]=='8'||
        str[0]=='9'){
            return (false);
        }
    else{
        return (true);
    }
}

bool bitir(char* str){
	
	if(!strcmp(str, "don0")){
		return (true);
	}
	 else
	 return (false);
	
}

// Eger burada tam sayi ise
// true donecektir
bool tamSayiMi(char* str)
{
    int i;
    int len = strlen(str);

    if (len == 0){
         return (true);
    }
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9')
            
            return (false);
            
    }
    
    
    return (true);
}

// Virgullu deger var ise true donecektir
bool virgulluSayiMi(char* str)
{
    int i, len = strlen(str);
    bool virgul = false;

    if (len == 0){
        return (false);
    }

    for (i = 0; i < len; i++) {
        if (str[i]!='0'&&str[i]!='1'&&str[i]!='2'
            &&str[i]!='3'&&str[i]!='4'&&str[i]!='5'
            &&str[i]!='6'&&str[i]!='7'&&str[i]!='8'
            &&str[i]!='9'&&str[i]!='.'){
            return (false);
        }
        if (str[i] == '.'){
            virgul = true;
        }
    }
    return (virgul);
}

// burada ise parcalinan kelime, karakter, operator veya numarayi
// birlestirmek icin altDizi yapilmistir
char* altDizi(char* str, int left, int right)
{
    int i;
    char* subStr;
    subStr = (char*)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Burda girilen stringi ayristirma yapiyoruz 
void ayristirici(char* str)
{
	int id=0,kw=0,num=0,op=0,er=0;
    int left=0, right=0;
    int len = strlen(str);
    printf("**************************************************************************\n");
    while (right <= len && left <= right) {
        if (sonlandiriciVarMi(str[right]) == false){
            right++;
            
        }
        if (sonlandiriciVarMi(str[right])==true&& left==right) {
            if (operatorVarMi(str[right]) == true){
            	
                printf("'%c' : Islem opertorudur.\n", str[right]);
                op++;
                
            }
            right++;
            left = right;
        } else if (sonlandiriciVarMi(str[right]) == true && left != right
                   || (right == len && left != right)) {
                   	
            char* alt_dizi = altDizi(str, left, right - 1);
            
            if (bitir(alt_dizi)==true){
		
            		break;
            }
            
            else if(operatorMu(alt_dizi)== true){
            	
            	printf("'%s' : Islem Operatorudur\n", alt_dizi);
            	op++;
			}
			
            else if (anahtarKelimeMi(alt_dizi) == true){
                printf("'%s' : Anahtar Kelimedir\n", alt_dizi);
                kw++;
            }

            else if (tamSayiMi(alt_dizi) == true){
                printf("'%s' : Tam Sayidir\n", alt_dizi);
                
                
                num++;
            }
            else if (virgulluSayiMi(alt_dizi) == true){
                printf("'%s' : Virgullu Sayidir\n", alt_dizi);
                num++;
            }
            else if ( gecerliMi(alt_dizi) == true
                     && sonlandiriciVarMi(str[right - 1]) == false){
                printf("'%s' : Gecerli bir kelime veya karakterdir. \n", alt_dizi);
                id++;
            }
            else if (gecerliMi(alt_dizi) == false
                     && sonlandiriciVarMi(str[right - 1]) == false){
                printf("'%s' : Hata boyle bir ayristirma yoktur!!!!!\n", alt_dizi);
                er++;
                
            } 
		
            left = right;
        }
    }
    printf("**************************************************************************\n");
    printf("Anahtar kelime: %d\nTanimlayici: %d\nIslem Operatoru: %d\nSayi: %d\nHatali Karakter: %d\n",kw,id,op,num,er);
    
    printf("**************************************************************************");
    
    
    return;
}

int main()
{
    char *buffer = NULL;
    size_t size = 0;
    FILE *fp = fopen("islem.txt", "r");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    rewind(fp);

    buffer = malloc((size + 1) * sizeof(*buffer));

    fread(buffer, size, 1, fp);

    buffer[size] = '\0';

    ayristirici(buffer);
    return (0);
}

