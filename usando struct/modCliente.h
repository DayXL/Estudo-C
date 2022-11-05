typedef struct cliente Cliente;

struct cliente {

    char nomeDoCliente[100];
    char cpf[12];
    char numero[12];
    char email[100];
    int ativo;

};

void cadastrarCliente(void);
void validarNomeCliente(char *nome);
void validarCPF(char *cpf);
void validarNumeroCelular(char *numero);
void validarEmail(char *email);
void exibCliente(Cliente *clt);
void salArqClt(Cliente* clt);
void lerArqClt(void);
Cliente* acharClt(char *cpf);
void pesqClt(void);