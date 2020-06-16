/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 11:21:08 by aurelienbuc       #+#    #+#             */
/*   Updated: 2020/06/02 16:58:02 by aurelienbuc      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libcube3d.h"

int main()
{
    Display* ConnectionServeurX = XOpenDisplay(NULL);    // Connection au serveur X

  int CouleurBlanche = WhitePixel(ConnectionServeurX, DefaultScreen(ConnectionServeurX));   // déclaration d'une couleur blanche

  Window Fenetre = XCreateSimpleWindow(ConnectionServeurX,
				      RootWindow(ConnectionServeurX,DefaultScreen(ConnectionServeurX)),
				      0,0,200,100,0,CouleurBlanche,CouleurBlanche);    // Création d'un fenêtre de coordonnées 0,0 et de 200 sur 200, de couleur de fond blanche et bordure blanche
  XMapWindow(ConnectionServeurX, Fenetre);       // Mapping de la fenêtre
  XSelectInput(ConnectionServeurX, Fenetre,KeyPressMask);       // On séelectionne les évennements utiles , KeyPressMask pour capturer un événement clavier

  XEvent Evenement;        // déclaration d'u événement
  do {
    XNextEvent(ConnectionServeurX, &Evenement);
    XFlush(ConnectionServeurX);
  } while(Evenement.type != KeyPress);   // afficher la fenêtre tant qu'aucune touche n'est pressée

  return 0;
}