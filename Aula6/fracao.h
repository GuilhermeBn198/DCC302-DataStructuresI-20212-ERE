
typedef struct {
	int numerador;
	int denominador; 
} fracao;

fracao cria_fracao(int n, int d);
int get_numerador(fracao f);
int get_denominador(fracao f);
int mdc(int n1, int n2);
int mmc(int n1, int n2);
fracao soma_fracao(fracao f1, fracao f2);

//this is a TAD where we declare the signature of the encapsulated functions that we can use in another programs with the type of the function, the name, the number of arguments and the TYPE of the arguments which require to work properly