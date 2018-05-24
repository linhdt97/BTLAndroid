package vn.edu.hust.student.linhdt.project;

import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;
import org.opencv.android.OpenCVLoader;
import org.opencv.android.Utils;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity {
    private static final String TAG="MainActivity";
    private ImageView imgView;
    Button btnChon, btnNhandang;
    Uri uriProvider = android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI;
    Bitmap imgBitmap;

    static {
        System.loadLibrary("MyLibs");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        imgView = findViewById(R.id.imgView);
        imgView.setImageResource(R.drawable.anhtrong);

        btnChon = (Button) findViewById(R.id.btnChon);
        btnNhandang = (Button) findViewById(R.id.btnNhandang);
        btnChon.setOnClickListener(new ClickHandler());

        btnNhandang.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (imgBitmap != null) {
                    Mat tmp = processImg();
                    Utils.matToBitmap(tmp,imgBitmap);
                    imgView.setImageBitmap(imgBitmap);
                }
                else {
                    Toast.makeText(MainActivity.this, "Vui lòng chọn ảnh cần nhận dạng", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private class ClickHandler implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            try {
                Intent myActivity2 = new Intent( Intent.ACTION_PICK, uriProvider);
                startActivityForResult(myActivity2, 222);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (OpenCVLoader.initDebug()) {
            Log.i(TAG, "Opencv successfully loaded");
        }
        else  {
            Log.i(TAG, "Opencv not loaded");
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode != 222 || resultCode != RESULT_OK) {
            super.onActivityResult(requestCode, resultCode, data);
            return;
        }
        switch (requestCode) {
            case (222): {
                try {
                    final Uri imageUri = data.getData();
                    final InputStream imageStream = getContentResolver().openInputStream(imageUri);
                    imgBitmap = BitmapFactory.decodeStream(imageStream);
                    imgView.setImageBitmap(imgBitmap);
                } catch (IOException e) {
                    Log.e(TAG, e.getMessage());
                }
            }
        }
    }

    public Mat processImg() {
        Mat mat = new Mat (imgBitmap.getWidth(), imgBitmap.getHeight(), CvType.CV_8UC4);
        Bitmap bmp32 = imgBitmap.copy(Bitmap.Config.ARGB_8888, true);
        Utils.bitmapToMat(bmp32, mat);
        OpenCvClass.catDetection(mat.getNativeObjAddr());
        OpenCvClass.dogDetection(mat.getNativeObjAddr());
        //OpenCvClass.chickenDetection(mat.getNativeObjAddr());
        //OpenCvClass.buffaloDetection(mat.getNativeObjAddr());
        //OpenCvClass.pigDetection(mat.getNativeObjAddr());
        //OpenCvClass.peopleDetection(mat.getNativeObjAddr());
        return mat;
    }
}
