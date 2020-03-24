import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class FileServer {

	public static DatagramSocket serverSocket;
	public static DatagramPacket datagramPacket;
	public static BufferedReader bufferedReader;
	public static InetAddress inetAddress;
	public static byte buffer[]= new byte[35535];
	public static int cport = 222, sport = 6789;

	public static void main(String[] args) throws IOException {
		serverSocket = new DatagramSocket(sport);
		datagramPacket = new DatagramPacket(buffer, buffer.length);
		// br = new BufferedReader(new InputStreamReader(System.in));
		inetAddress = InetAddress.getLocalHost();
		 
		System.out.println("Server is Running...");
		while (true) {
			serverSocket.receive(datagramPacket); 
			String fileName = new String(datagramPacket.getData(), 0, datagramPacket.getLength());
			if (fileName.equals("exit")) {
				System.out.println("Terminated...");
				break;
			}
			
			System.out.println("File name entered by client is : " + fileName);
 
			buffer = FileServer.readTextFile(fileName);			
			 
			
			serverSocket.send(new DatagramPacket(buffer, buffer.length, inetAddress, cport));
			
			buffer = new byte[35535];
		}
	}

	public static byte[] readTextFile(String fileName) throws IOException {
		Path filePath = Paths.get("C:\\Users\\patehars\\Desktop", fileName);
		byte[] content;
		try {
			content = Files.readAllBytes(filePath);
			
		} catch (Exception e) {
			String message = "No such file found \n" + " IP address of server is : " + InetAddress.getLocalHost();
			content = message.getBytes();
		}
		return content;
	}
	
	public static List<String> readTextFileByLines(String fileName) throws IOException {
		List<String> lines = null;
		try {
			Path filePath = Paths.get("C:\\Users\\patehars\\Desktop", fileName);
			lines = Files.readAllLines(filePath);

		} catch (IOException e) {
			System.out.println(e);
		}
		return lines;
	}
}
