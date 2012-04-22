package ch.epfl.cubesatremote;

import java.io.IOException;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.app.Activity;
import android.graphics.Typeface;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;



public class CubeSatRemoteActivity extends Activity {
	/** Called when the activity is first created. */
	

	private TableLayout MainLayout;
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		//setContentView(R.layout.main);

		
		
		
		MainLayout = new TableLayout(this);
        MainLayout.setLayoutParams(new TableRow.LayoutParams(TableRow.LayoutParams.FILL_PARENT, TableRow.LayoutParams.FILL_PARENT));
        MainLayout.setStretchAllColumns(true);
 
        getLatestPacket();
        
        
        
      
        
        //Set the view
        setContentView(MainLayout);
        

	}


	public void getLatestPacket() {
		System.out.println("CubeSatRemoteActivity.getLatestPacket()");
		
		//Create the layout
        
        MainLayout.removeAllViews();
        
        Button refresh = new Button(this);
        refresh.setText("Refresh");
        
        refresh.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				getLatestPacket();
			}
		});
        
        MainLayout.addView(refresh);
        
        
        
        
        
        
        TableRow rowH = new TableRow(this);
        TextView id = new TextView(this);
        id.setText("ID");
        id.setTypeface(null,Typeface.BOLD);
        TextView data = new TextView(this);
        data.setText("data");
        data.setTypeface(null,Typeface.BOLD);
        //text1.setGravity(android.view.Gravity.RIGHT);
        rowH.addView(id);
        rowH.addView(data);
        MainLayout.addView(rowH);
        
        JSONArray jsonArray = null;
        
        try {
			jsonArray = new JSONArray(ManageData.getTEXT("http://209.236.123.60:3000/latestpackages"));
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        
        
        
		for (int i = 0; i < jsonArray.length(); i++) {

			JSONObject rec;
			int id_ = 0;
			String data_ = null;
			
			try {
				rec = jsonArray.getJSONObject(i);
				id_ = rec.getInt("id");
				data_ = rec.getString("data");
				
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
        	//Create the second row and add two text views
            TableRow row = new TableRow(this);
            TextView text = new TextView(this);
            text.setText("" + id_);
            TextView text1 = new TextView(this);
            text1.setText(data_ );
            //text1.setGravity(android.view.Gravity.RIGHT);
            row.addView(text);
            row.addView(text1);
            MainLayout.addView(row);
        }
	}
	
	
	
	

}