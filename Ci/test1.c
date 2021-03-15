// листинг 2ой программы
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *enpv[])
{
	pid_t num;
	num = fork(); // порождаем новый процесс.
	if(num == 0)
	{
		execl('test2',NULL,NULL);
	/* если дочерний процесс, то заменяем контекст дочернего процесса и
	теперь запустилась 2-я программа */
	}
	else{
		if(num > 0){
		printf('Parent process\n\n');
		}
	}
	return 0;
}
