#include<stdio.h>
#include<string.h>
int is(const char *psz){
		if(!psz||!strlen(psz))
				return 0;
/*		int i;
		for(i=0;psz[i];i++)
				if(psz[i]<'0'||psz[i]>'9')
				//if(!is(psz[i]))
					return 0;
		return 1;
*/

	return strspn(psz,"01234567")==strlen(psz);
}
int is_char (const char *psz)
{
		if(!psz||!strlen(psz))
				return 0;
		return strspn(psz,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz")==strlen(psz);	


}
int main()
{
		printf("%d\n",is("123456"));
		printf("%d\n",is("asdf123"));		
		printf("%d\n",is("ab"));		
		printf("%d\n",is_char("13asdfab"));		
		printf("%d\n",is_char("abcd"));		


		return 0;
}
