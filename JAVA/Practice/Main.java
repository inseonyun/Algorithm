import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    public static void io() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        while(st.hasMoreTokens()) {
            bw.write(st.nextToken() + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void nonSpaceContinuedInteger() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        char tmp[] = st.nextToken().toCharArray();

        int arr[] = new int[tmp.length];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = tmp[i] - '0';
        }

        for (int i = 0; i < arr.length; i++) {
            bw.write(String.valueOf(arr[i]) + " ");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        io();
//        nonSpaceContinuedInteger();
    }
}
