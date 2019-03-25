package com.weimeitc.wmshell;


import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.support.v4.app.ActivityCompat;
import android.util.TypedValue;
import android.widget.Toast;

import com.ai.base.AIBaseActivity;
import com.ai.webplugin.AIWebViewActivity;
import com.ai.webplugin.config.GlobalCfg;

import java.io.InputStream;

public class EnterActivity extends AIBaseActivity {
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
            if (flavor.equalsIgnoreCase("AIPlan")) {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addr"));
            } else {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addrTest"));
            }

            startActivity(intent);
            finish();
        } catch (Exception e) {
        }
    }
}
