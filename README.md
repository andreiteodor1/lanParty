Pentru a implementa lista cu informatiile din fisierul d.in, am creat o structura
    de tip ECHIPA, care va fi folosita pentru fiecare nod din lista noastra. In functia 
    pentru crearea listei am primit ca argument pointer catre fisierul d.in din care 
    citim, am citit numarul de echipe, pentru fiecare echipa citind intr-un buffer numele
    echipei, mai apoi alocand dinamic spatiu pentru nume intr-o variabila. Fiecare echipa 
    are un numar de jucatori, pentru fiecare repetand citirea intr-un buffer si apoi alocarea 
    dinamica a numelor fiecarui jucator si am stocat intr-o variabila din structura numarul de 
    puncte ale fiecaruia. Apoi, in main am parcurs lista de la pointerul head, iar pentru 
    fiecare echipa am printat in fisierul r.out numele acesteia.
        In continuare, la task-ul nr.2, am luat o variabila "nr_teams", am parcurs lista de la 
    head si am aflat numarul de echipe, pentru a il avea salvat si in afara functiei. Am creat
    o functie 'Calcul Putere' cu ajutorul careia am putut sa determin cel mai mare numar n, 
    multiplu al lui 2, mai mic decat nr curent de echipe. Apoi, cu un for de la 0 la numarul
    de echipe care trebuiau eliminate pentru a ajunge la acel numar determinat mai sus, am 
    sters cate o echipa la fiecare pas al for-ului, cu ajutorul functiei 'delete_team', in 
    care am calculat fiecarei echipe punctajul, echipele cu cel mai mic punctaj fiind sterse
    din lista; Apoi, cu inca un for am printat in fisierul r.out numele echipelor ramase.
        La task-ul 3, am incercat sa implementez coada cu ajutorul unei functii 'createQueue'
    si cu ajutorul functiei 'enQueue' sa adaug cate un element in coada, fiecare element 
    continand o adresa de tip ECHIPA* a unei echipe din lista de la task-ul 2. Apoi, cu functia
    deQueue am incercat sa imi returnez un pointer catre adresa fiecarei echipe, cu care sa
    lucrez mai departe.
