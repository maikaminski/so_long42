/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:39:45 by makamins          #+#    #+#             */
/*   Updated: 2025/03/28 15:47:37 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    iniciarjogo();
        iniciarmapa();
        iniciarjogador();
        iniciarcoletáveis();
        teclasdemovimento();
        movimentarjogador();
        contarmovimentos();
            imprimirmovimentosnoterminal();
        saída();
        
    erros();
    limpeza();
    destruirjanela();
    
        
}