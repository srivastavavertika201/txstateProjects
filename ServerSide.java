import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ServerSide {

	public static DatagramSocket serverSocket;
	public static DatagramPacket datagramPacket;
	public static BufferedReader bufferedReader;
	public static InetAddress inetAddress;
	public static byte buffer[] = new byte[35535];
	public static int clientPort = 222, serverPort = 6789;

	public static void main(String[] args) throws IOException {
		serverSocket = new DatagramSocket(serverPort);
		datagramPacket = new DatagramPacket(buffer, buffer.length);
		bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		inetAddress = InetAddress.getLocalHost();

		System.out.println("Server is Running...");
		while (true) {
			serverSocket.receive(datagramPacket);
			String clientInput = new String(datagramPacket.getData(), 0, datagramPacket.getLength());
			if (clientInput.equals("exit")) {
				System.out.println("Terminated...");
				break;
			}

			System.out.println("client said : " + clientInput);
			String str3 = new String(bufferedReader.readLine());
	        buffer = str3.getBytes();
	          
			serverSocket.send(new DatagramPacket(buffer, buffer.length, inetAddress, clientPort));

			buffer = new byte[35535];
		}
	}
}
