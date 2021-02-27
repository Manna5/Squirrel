short int squirrel(const char* pattern,const char* text);
static short int squirrel_star(const char* pattern,const char* text);

short int squirrel(const char* pattern,const char* text){
	if(!pattern || !text){
		return 0;
	}else if(!*text){
		return 1;
	}else if(*pattern==*text || *pattern=='?'){
		return squirrel(++pattern,++text) || squirrel(++pattern,text);
	}else if(*pattern=='+'){
		return squirrel(++pattern,++text);
	}else if(*pattern=='#' && *text>='0' && *text<='9'){
		return squirrel(++pattern,++text);
	}else if(*pattern=='*'){
		return squirrel_star(++pattern,text);
	}else{
		return 0;
	}
}

static short int squirrel_star(const char* pattern,const char* text){
	if(!*text && *pattern){
		return 0;
	}else if(squirrel(pattern,text)){
		return 1;
	}else{
		return squirrel_star(pattern,++text);
	}
}
