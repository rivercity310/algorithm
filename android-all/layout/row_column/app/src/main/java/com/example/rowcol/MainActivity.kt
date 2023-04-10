package com.example.rowcol

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.border
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.layout.FirstBaseline
import androidx.compose.ui.layout.LastBaseline
import androidx.compose.ui.layout.SubcomposeSlotReusePolicy
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.rowcol.ui.theme.RowColTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            RowColTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colors.background
                ) {
                   MainScreen()
                }
            }
        }
    }
}

@Composable
fun MainScreen() {
    Column(
        modifier = Modifier.width(600.dp),
        horizontalAlignment = Alignment.End
    ) {

        Row(
            modifier = Modifier
                .align(Alignment.Start)
                .then(Modifier.height(300.dp))
        ) {
            TextCell("1", Modifier.align(Alignment.Top))
            TextCell("2", Modifier.align(Alignment.CenterVertically))
            TextCell("3", Modifier.align(Alignment.Bottom))
        }

        Spacer(modifier = Modifier.height(30.dp))

        Row(
            modifier = Modifier.align(Alignment.CenterHorizontally)
        ) {
            Text(
                text = "Large Text\nMore Text",
                Modifier.alignBy(FirstBaseline),
                fontSize = 40.sp,
                fontWeight = FontWeight.Bold
            )

            Text(
                text = "small text",
                Modifier.paddingFrom(
                    alignmentLine = FirstBaseline,
                    before = 80.dp, after = 0.dp
                ),
                fontSize = 32.sp,
                fontWeight = FontWeight.Bold
            )
        }
    }
}


@Composable
fun TextCell(text: String, modifier: Modifier = Modifier) {
    val cellModifier = Modifier
        .padding(4.dp)
        .size(100.dp, 100.dp)
        .border(width = 4.dp, color = Color.Black)

    Text(
        text = text,
        modifier = cellModifier.then(modifier),
        fontSize = 70.sp,
        fontWeight = FontWeight.Bold,
        textAlign = TextAlign.Center
    )
}

@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    RowColTheme {
        MainScreen()
    }
}