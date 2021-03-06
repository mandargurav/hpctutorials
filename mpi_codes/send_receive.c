#include"stdio.h"
#include"mpi.h"

main(int argc, char **argv)
{
	int myid, size;
	int data = 20;
	int send_data[2], receive_data[2];
	MPI_Status status;
	
	//Initialize MPI environment 
	MPI_Init(&argc,&argv);
	
	//Get total number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	//Get my unique identification among all processes
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	
	//If root
	if(myid==0)
	{
		//Initialize data to be sent
		send_data[0] = 0;
		send_data[1] = 1;
		
		//Print the data to be sent
		printf("\nmyid: %d \t send_data[0] = %d", myid, send_data[0]);
		printf("\nmyid: %d \t send_data[1] = %d", myid, send_data[1]);
		
		//Send data
		MPI_Send(send_data, 2, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("\nData sent.\n");	
	}
	if(myid==1)	// Process with id exactly equal to 1
	{
		//Initialize receive array to some other data
		receive_data[0] = 10;
		receive_data[0] = 20;
		
		//Receive data
		//MPI_Recv(receive_data, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		
		
		
		
		
		
		
		MPI_Recv(receive_data, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		
		
		
		
		
		
		
		
		printf("\nData received.");
		
		//Print received data
		printf("\nmyid: %d \t receive_data[0] = %d", myid, receive_data[0]);
		printf("\nmyid: %d \t receive_data[1] = %d", myid, receive_data[1]);
		
		printf("\n\nProgram exit!\n");	
	}
	
	//End MPI environment        
	MPI_Finalize();
}
