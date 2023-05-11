#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verifier_elf(unsigned char *e_ident);
void afficher_magic(unsigned char *e_ident);
void afficher_classe(unsigned char *e_ident);
void afficher_donnees(unsigned char *e_ident);
void afficher_version(unsigned char *e_ident);
void afficher_abi(unsigned char *e_ident);
void afficher_osabi(unsigned char *e_ident);
void afficher_type(unsigned int e_type, unsigned char *e_ident);
void afficher_entree(unsigned long int e_entry, unsigned char *e_ident);
void fermer_elf(int elf);

/**
 * verifier_elf - Vérifie si un fichier est un fichier ELF.
 * @e_ident: Un pointeur vers un tableau contenant les nombres magiques ELF.
 *
 * Description : Si le fichier n'est pas un fichier ELF - code de sortie 98.
*/
void verifier_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
	if (e_ident[index] != 127 &&
	e_ident[index] != 'E' &&
	e_ident[index] != 'L' &&
	e_ident[index] != 'F')
	{
		dprintf(STDERR_FILENO, "Erreur : Ce n'est pas un fichier ELF\n");
		exit(98);
	}
	}
}

/**
 * afficher_magic - Affiche les nombres magiques d'un en-tête ELF.
 * @e_ident: Un pointeur vers un tableau contenant les nombres magiques ELF.
 *
 * Description : Les nombres magiques sont séparés par des espaces.
*/
void afficher_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magique : ");

	for index = 0; index < EI_NIDENT; index++
	{
	    printf("%02x", e_ident[index]);

	if (index == EI_NIDENT - 1)
	printf("\n");
	else
	printf(" ");
	}
}

/**
 * afficher_classe - Affiche la classe d'un en-tête ELF.
 * @e_ident: Un pointeur vers un tableau contenant la classe ELF.
*/
void afficher_classe(unsigned char *e_ident)
{
	printf(" Classe : ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
	printf("none\n");
	break;
	case ELFCLASS32:
	printf("ELF32\n");
	break;
	case ELFCLASS64:
	printf("ELF64\n");
	break;
	default:
	printf("<inconnu : %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * afficher_donnees - Affiche les données d'un en-tête ELF.
 * @e_ident: Un pointeur vers un tableau contenant la classe ELF.
 */
void afficher_donnees(unsigned char *e_ident)
{
	printf(" Données : ");

	switch (e_ident[EI_DATA])
{
	case ELFDATANONE:
	printf("none\n");
	break;
	case ELFDATA2LSB:
	printf("complément à 2, petit-boutiste\n");
	break;
	case ELFDATA2MSB:
	printf("complément à 2, grand-boutiste\n");
	break;
	default:
	printf("<inconnu : %x>\n", e_ident[EI_CLASS]);
	}
}


