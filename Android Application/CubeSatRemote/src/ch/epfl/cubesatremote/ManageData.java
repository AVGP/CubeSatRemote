package ch.epfl.cubesatremote;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;


public class ManageData {

	ManageData() {
		getData();
	}
	
	public void getData () {

		JSONArray jsonArray = null;
		
		
		try {
			jsonArray = new JSONArray(getTEXT("http://209.236.123.60:3000/latestpackages"));
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		for (int i = 0; i < jsonArray.length(); i++) {
			try {
				JSONObject rec = jsonArray.getJSONObject(i);
				int id = rec.getInt("id");
				System.out.println("id:" + id);
				
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		
	}
	
	public static String getTEXT ( String url) throws IOException { 
		if (url == null || url.length() == 0) { 
			throw new IllegalArgumentException("url cannot be null or empty"); 
		} 
		final HttpURLConnection conn = (HttpURLConnection) new URL(url).openConnection(); 
		final BufferedReader buf = new BufferedReader(new InputStreamReader(conn.getInputStream())); 
		final StringBuilder page = new StringBuilder(); 
		final String lineEnd = System.getProperty("line.separator"); 
		String line; 
		try { 
			while (true) { 
				line = buf.readLine(); 
				if (line == null) { 
					break; 
				} 
				page.append(line).append(lineEnd); 
			} 
		} finally { 
			buf.close(); 
		} 

		try {
			return page.toString().substring(0, page.toString().length() -1);
		} catch (Exception e) {
			return "";
		}

	}
}
