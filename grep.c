#include <stdio.h>

/*returns length of string*/
int my_strlen(const char *str){
	int len;
	for(len = 0;str[len] != '\0';len++){}
	return len;
}

/*prints all the lines containing "pat" in "file" when no option is given*/
void func00(char *pat,FILE *file){
	char line[1001];
	int patlen = my_strlen(pat); 
	int linelen;
	int linenum = 0;
	int found;
	while(feof(file) == 0){
		found = 0;
		fgets(line,1000,file);
		linenum += 1;
		if(line[my_strlen(line)-1] == '\n'){line[my_strlen(line)-1] = '\0';}
		linelen = my_strlen(line);
		for(int i=0;(i<=(linelen-patlen));i++){
			for(int j=0;j<patlen;j++){
				if(pat[j] != '.'){
					if((pat[j] != line[i+j])){break;}
				}
				if(j == patlen-1){found = 1;}
			}
			if(found == 1){printf("%d: %s\n",linenum,line);break;}
		}
	}
	return;
}

/*prints all the lines not containing "pat" in "file" when "-v" option is given*/
void func01(char *pat,FILE *file){
	char line[1001];
	int patlen = my_strlen(pat); 
	int linelen;
	int linenum = 0;
	int found;
	while(feof(file) == 0){
		found = 0;
		fgets(line,1000,file);
		linenum += 1;
		if(line[my_strlen(line)-1] == '\n'){line[my_strlen(line)-1] = '\0';}
		linelen = my_strlen(line);
		for(int i=0;(i<=(linelen-patlen));i++){
			for(int j=0;j<patlen;j++){
				if(pat[j] != '.'){
					if((pat[j] != line[i+j])){break;}
				}
				if(j == patlen-1){found = 1;}
			}
			if(found == 1){break;}
		}
		if(found == 0){printf("%d: %s\n",linenum,line);}
	}
	return;
}

/*prints all the lines containing "pat" in "file" when "-i" option is given(ignores case of "pat")*/
void func10(char *pat,FILE *file){
	char line[1001];
	int patlen = my_strlen(pat); 
	int linelen;
	int linenum = 0;
	int found;
	while(feof(file) == 0){
		found = 0;
		fgets(line,1000,file);
		linenum += 1;
		if(line[my_strlen(line)-1] == '\n'){line[my_strlen(line)-1] = '\0';}
		linelen = my_strlen(line);
		for(int i=0;(i<=(linelen-patlen));i++){
			for(int j=0;j<patlen;j++){
				if(pat[j] != '.'){
					if((pat[j]>96 && pat[j]<123)){
						if(line[i+j]>96 && line[i+j]<123){
							if((pat[j] != line[i+j])){break;}
						}
						else if(line[i+j]>64 && line[i+j]<91){
							if((pat[j] != (line[i+j]+32))){break;}
						}
						else{break;}
					}
					else if((pat[j]>64 && pat[j]<91)){
						if(line[i+j]>96 && line[i+j]<123){
							if(((pat[j]+32) != line[i+j])){break;}
						}
						else if(line[i+j]>64 && line[i+j]<91){
							if((pat[j] != (line[i+j]))){break;}
						}
						else{break;}
					}
					else if((pat[j] != (line[i+j]))){break;}
				}
				if(j == patlen-1){found = 1;}
			}
			if(found == 1){printf("%d: %s\n",linenum,line);break;}
		}
	}
	return;
}

/*prints all the lines not containing "pat" in "file" when "-i" and "-v" options are given(ignores case of "pat")*/
void func11(char *pat,FILE *file){
	char line[1001];
	int patlen = my_strlen(pat); 
	int linelen;
	int linenum = 0;
	int found;
	while(feof(file) == 0){
		found = 0;
		fgets(line,1000,file);
		linenum += 1;
		if(line[my_strlen(line)-1] == '\n'){line[my_strlen(line)-1] = '\0';}
		linelen = my_strlen(line);
		for(int i=0;(i<=(linelen-patlen));i++){
			for(int j=0;j<patlen;j++){
				if(pat[j] != '.'){
					if((pat[j]>96 && pat[j]<123)){
						if(line[i+j]>96 && line[i+j]<123){
							if((pat[j] != line[i+j])){break;}
						}
						else if(line[i+j]>64 && line[i+j]<91){
							if((pat[j] != (line[i+j]+32))){break;}
						}
						else{break;}
					}
					else if((pat[j]>64 && pat[j]<91)){
						if(line[i+j]>96 && line[i+j]<123){
							if(((pat[j]+32) != line[i+j])){break;}
						}
						else if(line[i+j]>64 && line[i+j]<91){
							if((pat[j] != (line[i+j]))){break;}
						}
						else{break;}
					}
					else if((pat[j] != (line[i+j]))){break;}
				}
				if(j == patlen-1){found = 1;}
			}
			if(found == 1){break;}
		}
		if(found == 0){printf("%d: %s\n",linenum,line);}
	}
	return;
}

int main(int argc,char **argv){
	int ignore=0;
	int invert=0;
	for(int i=1;i<argc;i++){
		if(*(argv[i]) == '-'){
			if((*(argv[i]+1) == 'i')){
				ignore = 1;
			}
			else if ((*(argv[i]+1) == 'v')){
				invert = 1;
			}
		}
	}
	char *pat = argv[(argc-2)];
	char *file_name = argv[(argc-1)];
	FILE *file;
	file = fopen(file_name,"r");
	if(ignore==0 && invert==0){func00(pat,file);}
	else if(ignore==0 && invert==1){func01(pat,file);}
	else if(ignore==1 && invert==0){func10(pat,file);}
	else if(ignore==1 && invert==1){func11(pat,file);}
	
	fclose(file);
	return 0;
}
