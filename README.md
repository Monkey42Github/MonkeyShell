# Minishell 42

Ce projet est une implémentation d'un mini-interpréteur de commandes (minishell) en langage C, réalisé dans le cadre du cursus de l'école 42.

## Description

Un minishell est un programme qui agit comme un interpréteur de commandes simplifié, similaire au shell Unix (bash, zsh, etc.). Il permet à l'utilisateur d'exécuter des commandes système, de naviguer dans le système de fichiers, et d'effectuer des opérations de base telles que la redirection de flux d'entrée/sortie et la gestion des processus en arrière-plan.

## Fonctionnalités

- Exécution de commandes système.
- Gestion des commandes intégrées (ex. `cd`, `echo`, `pwd`).
- Gestion des opérateurs de redirection (`<`, `>`, `>>`).
- Prise en charge des tubes (`|`) pour la communication entre processus.
- Gestion des signaux pour le contrôle des processus en arrière-plan.

## Compilation et Exécution

1. Clonez ce dépôt sur votre machine :
  ```
  git clone <lien vers le dépôt Git>
  ```
2. Accédez au répertoire du projet :
  ```
  cd Minishell
  ```
3. Compilez le projet en exécutant la commande :
  ```
  make
  ```
4. Lancez le minishell en exécutant :
  ```
   ./minishell
  ```

## Explication

Le minishell est construit en utilisant principalement les appels système de bas niveau comme `fork()`, `exec()` et `wait()`. Il analyse les commandes entrées par l'utilisateur, les sépare en tokens et les exécute en fonction de la structure de la ligne de commande.

L'implémentation des fonctionnalités avancées telles que la gestion des redirections et des tubes nécessite une compréhension approfondie de la manipulation des descripteurs de fichiers et de la gestion des processus en C.

Le développement d'un minishell est un excellent exercice pour comprendre le fonctionnement interne des shells Unix et pour améliorer ses compétences en programmation système.
