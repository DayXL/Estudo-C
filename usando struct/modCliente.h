void cadastrarCliente(void);
void validarNomeCliente(void);
void validarCPF(void);
void validarNumeroCelular(void);
void validarEmail(void);

typedef struct cliente Cliente;

struct cliente {

    char nomeCliente[100];
    char cpf[12];
    char numero[12];
    char email[100];

};

