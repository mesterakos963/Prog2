import java.io.*;
import java.util.*;

public class L33tSpeak {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File("bemenet.txt"));
		PrintStream out = new PrintStream(new File("kimenet.txt"));
		leetSpeak(input, out);
	}
	
	public static void leetSpeak(Scanner input, PrintStream output) {
		while (input.hasNextLine()) {
			String sor = input.nextLine();
			Scanner tokens = new Scanner(sor);
			
			while (tokens.hasNext()) {
				String token = tokens.next();
				token = token.replace("a", "4");
				token = token.replace("o", "0");
				token = token.replace("l", "1");
				token = token.replace("e", "3");
				token = token.replace("t", "7");
				if (token.endsWith("s")) {
					token = token.substring(0, token.length() - 1) + "Z";
				}
				output.print("(" + token + ") ");
			}
			
			output.println();
		}	
	}
}