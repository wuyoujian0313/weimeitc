package com.weimeitc.wmshell;


import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.util.TypedValue;
import android.widget.Toast;

import com.ai.base.AIBaseActivity;
import com.ai.webplugin.AIWebViewActivity;
import com.ai.webplugin.config.GlobalCfg;
import com.anoah.lock.ScreenLocker;

import java.io.InputStream;

public class EnterActivity extends AIBaseActivity {
    private ScreenLocker locker;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.splash_layout);
        initParam();
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                enterHomeActivity();
            }
        }, 2000);
    }

    private void initParam() {
        GlobalCfg globalCfg = GlobalCfg.getInstance();
        try {
            InputStream is = getResources().getAssets().open("global.properties");
            globalCfg.parseConfig(is);
        } catch (Exception e) {
            e.printStackTrace();
        }

        String[] permissions = new String[]{Manifest.permission.CAMERA,
                Manifest.permission.ACCESS_FINE_LOCATION,
                Manifest.permission.READ_PHONE_STATE,
                Manifest.permission.WRITE_EXTERNAL_STORAGE,
                Manifest.permission.INTERNET };
        checkPermission(permissions);

        locker = new ScreenLocker(this);
        locker.lock();
    }

    private void checkPermission(String[] str) {
        if (Build.VERSION.SDK_INT >= 23) {
            for (String mS : str) {
                int checkCallPhonePermission = ContextCompat.checkSelfPermission(EnterActivity.this, mS);
                if (checkCallPhonePermission != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(EnterActivity.this, str, 333);
                    return;
                } else {

                }
            }
        } else {
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }

    private void enterHomeActivity() {
        Intent intent = new Intent(this, AIWebViewActivity.class);

        TypedValue typedValue = new TypedValue();
        getTheme().resolveAttribute(R.attr.colorPrimary, typedValue, true);
        final  int color = typedValue.data;
        intent.putExtra(AIWebViewActivity.backgroundColorKey, Color.WHITE);
        intent.putExtra(AIWebViewActivity.backgroundResIdKey,Color.WHITE);
        intent.putExtra(AIWebViewActivity.welcomeImageResId,R.mipmap.startpage);

        try {
            GlobalCfg globalCfg = GlobalCfg.getInstance();
            String flavor = BuildConfig.FLAVOR;
            if (flavor.equalsIgnoreCase("wmlogin")) {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addr.login"));
            } else if(flavor.equalsIgnoreCase("wmapp"))  {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addr.app"));
            } else if(flavor.equalsIgnoreCase("wmdingapp")) {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addr.dingapp"));
            }

            startActivity(intent);
            finish();
        } catch (Exception e) {
        }
    }
}
