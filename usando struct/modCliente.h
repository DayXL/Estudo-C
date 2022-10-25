void cadastrarCliente(void);
void validarNomeCliente(char *nome);
void validarCPF(char *cpf);
void validarNumeroCelular(char *numero);
void validarEmail(char *email);
void verCliente(void);

typedef struct cliente DadosCliente;

struct cliente {

    char nomeDoCliente[100];
    char cpf[12];
    char numero[12];
    char email[100];

};

