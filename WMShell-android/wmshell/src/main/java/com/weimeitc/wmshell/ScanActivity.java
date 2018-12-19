package com.weimeitc.wmshell;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.media.SoundPool;
import android.os.Bundle;
import android.os.Vibrator;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.ai.base.AIBaseActivity;
import cn.bingoogolapple.qrcode.core.QRCodeView;
import cn.bingoogolapple.qrcode.zbar.ZBarView;



public class ScanActivity extends AIBaseActivity implements QRCodeView.Delegate {

    private static final String TAG = ScanActivity.class.getSimpleName();

    private SoundPool soundPool;//声明一个SoundPool
    private int soundID;//创建某个声音对应的音频ID
    private QRCodeView mQRCodeView;
    private ImageView mImageView;
    private ProgressBar mProgressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scan);
        initView();
    }

    private void initView() {
        mQRCodeView = (ZBarView) findViewById(R.id.zbarview);
        mImageView = (ImageView) findViewById(R.id.imv_back);
        mProgressBar= (ProgressBar) findViewById(R.id.ProgressBar);
        mQRCodeView.setDelegate(this);
        mQRCodeView.startSpot();
        mProgressBar.setVisibility(View.INVISIBLE);
        mImageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View mView) {
                Intent intent = new Intent();
                intent.putExtra("result","");
                setResult(RESULT_OK,intent);
                finish();
            }
        });
        initBeepSound();

    }

    /**
     * 初始化音效
     */
    @SuppressLint("NewApi")
    private void initBeepSound() {
        soundPool=new SoundPool.Builder().build();
        soundID=soundPool.load(this,R.raw.scan,1);
    }

    /**
     * 播放扫码音效
     */
    private void playSound() {
        soundPool.play(
                soundID,
                0.9f,   //左耳道音量【0~1】
                0.9f,   //右耳道音量【0~1】
                0,     //播放优先级【0表示最低优先级】
                0,     //循环模式【0表示循环一次，-1表示一直循环，其他表示数字+1表示当前数字对应的循环次数】
                1     //播放速度【1是正常，范围从0~2】
        );
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
    }


    @Override
    public void onStart() {
        super.onStart();
        mQRCodeView.startCamera();
        mQRCodeView.showScanRect();
    }

    @Override
    public void onStop() {
        mQRCodeView.stopCamera();
        super.onStop();
    }
    //震动
    private void vibrate() {
        Vibrator vibrator = (Vibrator) getSystemService(VIBRATOR_SERVICE);
        vibrator.vibrate(200);
    }

    @Override
    public void onScanQRCodeSuccess(String mS) {
        Log.i(TAG, "result:" + mS);
//        Toast.makeText(this, mS, Toast.LENGTH_SHORT).show();
        playSound();
        vibrate();
        mProgressBar.setVisibility(View.VISIBLE);
        Intent intent = new Intent();
        intent.putExtra("result",mS);
        setResult(RESULT_OK,intent);
        finish();
    }

    @Override
    public void onScanQRCodeOpenCameraError() {
        Toast.makeText(this, "扫码错误", Toast.LENGTH_SHORT).show();
    }

}
